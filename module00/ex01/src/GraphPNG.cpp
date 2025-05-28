#include "Graph.hpp"
#include "crc.hpp"

static inline void	insert32(std::vector<uint8_t>& v, uint32_t num)
{
	v.push_back((num >> 24) & 0xFF);
	v.push_back((num >> 16) & 0xFF);
	v.push_back((num >> 8) & 0xFF);
	v.push_back(num & 0xFF);
}

static inline void	insert32(std::vector<uint8_t>& v, const char c[4])
{
	v.push_back(c[0]);
	v.push_back(c[1]);
	v.push_back(c[2]);
	v.push_back(c[3]);
}

static std::vector<uint8_t>	getIHDR(uint32_t wid, uint32_t hei)
{
	static const uint8_t	signature[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};// PNG signature
	std::vector<uint8_t>	ihdr_chunk;
	uint32_t				crc;
	std::vector<uint8_t>	data;

	// Build IHDR chunk
	insert32(ihdr_chunk, "IHDR");// Chunk type "IHDR"
	insert32(ihdr_chunk, wid);// Width (big-endian)
	insert32(ihdr_chunk, hei);// Height (big-endian)
	ihdr_chunk.push_back(0x01);// Bit depth (1)
	ihdr_chunk.push_back(0x00);// Color type (0)
	ihdr_chunk.push_back(0x00);// Compression (0)
	ihdr_chunk.push_back(0x00);// Filter (0)
	ihdr_chunk.push_back(0x00);// Interlace (0)

	crc = crc32(ihdr_chunk);// CRC for IHDR chunk (type + data)

	data.insert(data.end(), signature, signature + 8);// Signature
	insert32(data, 13);// Length (13 bytes)
	data.insert(data.end(), ihdr_chunk.begin(), ihdr_chunk.end());// IHDR chunk
	insert32(data, crc);// CRC (big-endian)
	return data;
}

static std::vector<uint8_t>	getIEND()
{
	static const uint8_t data[] = {

		0x00, 0x00, 0x00, 0x00, // Length
		'I', 'E', 'N', 'D', // Type/Name
		// No Data since length is 0
		0xAE, 0x42, 0x60, 0x82 // CRC/Checksum

	};
	return std::vector<uint8_t>(data, data + sizeof(data)/sizeof(data[0]));
}

static std::vector<uint8_t>	getIDAT(const std::set<Vector2>& points,
	uint32_t width, uint32_t height)
{
	//Convert points to bitmap with filter bytes
	std::vector<uint8_t> pixelData;
	std::set<Vector2>::const_iterator it = points.begin();
	
	for (uint32_t y = 0; y < height; ++y)
	{
		uint8_t currentByte = 0;
		uint8_t bitCounter = 7; // MSB first
		
		pixelData.push_back(0x00); // Filter byte (None)
		for (uint32_t x = 0; x < width; ++x)
		{
			if (it == points.end() ||
				static_cast<uint32_t>(it->x) != x || 
				static_cast<uint32_t>(it->y) != y)
				currentByte |= (1 << bitCounter);
			else
				++it;
			if (bitCounter-- == 0)
			{
				pixelData.push_back(currentByte);
				currentByte = 0;
				bitCounter = 7;
			}
		}	
		if (bitCounter != 7)// Handle partial byte at end of scanline
			pixelData.push_back(currentByte);
	}

	//Create zlib stream with DEFLATE (stored blocks)
	std::vector<uint8_t> zlibStream;
	
	// Zlib header (RFC 1950)
	zlibStream.push_back(0x78);// CM = DEFLATE, CINFO = 7 (32K window)
	zlibStream.push_back(0x01);// FLG: FCHECK = 1, FDICT = 0, FLEVEL = 0
	
	// DEFLATE blocks (stored/uncompressed)
	size_t pos = 0;
	while (pos < pixelData.size())
	{
		size_t blockSize = std::min<size_t>(pixelData.size() - pos, 65535);
		
		// Block header (BFINAL=0 if more blocks, BTYPE=00 for stored)
		zlibStream.push_back(pos + blockSize >= pixelData.size() ? 0x01 : 0x00);
		
		// Block length (little-endian)
		zlibStream.push_back(blockSize & 0xFF);
		zlibStream.push_back((blockSize >> 8) & 0xFF);
		zlibStream.push_back(~blockSize & 0xFF);
		zlibStream.push_back((~blockSize >> 8) & 0xFF);
		
		// Block data
		zlibStream.insert(zlibStream.end(), 
						 pixelData.begin() + pos, 
						 pixelData.begin() + pos + blockSize);
		pos += blockSize;
	}
	insert32(zlibStream, adler32(pixelData));// Adler-32 checksum

	//Create IDAT chunk
	std::vector<uint8_t> idat;
	uint32_t length = zlibStream.size();
	insert32(idat, length);// Chunk length (big-endian)
	insert32(idat, "IDAT");// Chunk type
	idat.insert(idat.end(), zlibStream.begin(), zlibStream.end());// Chunk data
	insert32(idat, crc32(std::vector<uint8_t>(idat.begin() + 4, idat.end())));// CRC-32, type & data
	return idat;
}

void	Graph::outputImage()
{
	std::ofstream			image("image.png");
	std::vector<uint8_t>	data;
	std::vector<uint8_t>	idat;
	std::vector<uint8_t>	iend;

	if (!image)
		throw std::runtime_error("cannot open image");

	data = getIHDR(static_cast<uint32_t>(size.x), static_cast<uint32_t>(size.y));
	idat = getIDAT(points, static_cast<uint32_t>(size.x), static_cast<uint32_t>(size.y));
	iend = getIEND();
	data.insert(data.end(), idat.begin(), idat.end());
	data.insert(data.end(), iend.begin(), iend.end());
	image.write(reinterpret_cast<const char*>(data.data()), data.size());
}
