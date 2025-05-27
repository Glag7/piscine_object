#include "Graph.hpp"

uint32_t crc32(const std::vector<uint8_t>& data);

Graph::Graph(const Vector2 &size) : size(size)
{
	if (size.x <= 0 || size.y <= 0)
		throw std::invalid_argument("dumbass");
}

void	Graph::addPoint(const Vector2 &point)
{
	if (point.x < 0.f || point.x > size.x || point.y < 0.f || point.y > size.y)
		throw (std::invalid_argument("point out of bounds"));
	points.insert(point);
}

void	Graph::addLine(const Vector2 &start, const Vector2 &end)
{
	if (start.x < 0.f || start.x > size.x || start.y < 0.f || start.y > size.y
		|| end.x < 0.f || end.x > size.x || end.y < 0.f || end.y > size.y)
		throw (std::invalid_argument("point out of bounds"));

	Vector2	delta = end - start;
	float	steps = std::abs(delta.x) > std::abs(delta.y) ? std::abs(delta.x) : std::abs(delta.y);
	Vector2	inc = Vector2(delta.x / steps, delta.y / steps);
	Vector2	pos = start;
	
	for (float i = 0.f; i <= steps; ++i)
	{
		addPoint(Vector2(static_cast<int>(pos.x), static_cast<int>(pos.y)));
		pos = pos + inc;
	}
}

void	Graph::readFile(const std::string &name)
{
	std::ifstream	file(name.c_str());
	std::string		line;

	if (!file)
		throw	std::invalid_argument(name + ": can't open file");
	while (getline(file, line))
	{
		const char	*line_char = line.c_str();
		char	*end;
		float	x = std::strtol(line_char, &end, 10);
		Vector2	start;
		Vector2	endpt;

		while (std::isspace(*end))
			++end;
		if (*end++ != '/')
		{
			std::cerr << name + ": invalid line\n";
			continue;
		}
		start = Vector2(x, std::strtol(end, &end, 10));
		while (std::isspace(*end))
			++end;
		if (*end == 0)
		{
			addPoint(start);
			continue;
		}
		else if (*end++ != '-')
		{
			std::cerr << name + ": invalid line\n";
			continue;
		}
		x = std::strtol(end, &end, 10);
		while (std::isspace(*end))
			++end;
		if (*end++ != '/')
		{
			std::cerr << name + ": invalid line\n";
			continue;
		}
		endpt = Vector2(x, std::strtol(end, &end, 10));
		while (std::isspace(*end))
			++end;
		if (*end == 0)
			addLine(start, endpt);
		else
			std::cerr << name + ": invalid line\n";
	}
}

void	Graph::outputConsole()
{
	for (std::set<Vector2>::iterator	it = points.begin(); it != points.end(); ++it)
		std::cout << *it << "\n";
	std::set<Vector2>::iterator	it = points.begin();
	Vector2						pos;
	std::string					line;

	std::cout << "  ";
	for (int i = 0; i < size.x; ++i)
	{
		if (i < 11)
			std::cout << " ";
		std::cout << i;
	}
	std::cout << "\n";
	for (; pos.y < size.y; ++pos.y)
	{
		line = "";
		for (pos.x = 0; pos.x < size.x; ++pos.x)
		{
			if (it == points.end() || pos < *it)
				line += " .";
			else
			{
				line += " X";
				++it;
			}
		}
		std::cout << ((pos.y < 10) ? " " : "") << pos.y << line << "\n";
	}
}

static std::vector<uint8_t>	getPngStart(uint32_t wid, uint32_t hei)
{
	uint8_t		*widarr = reinterpret_cast<uint8_t *>(&wid);
	uint8_t		*heiarr = reinterpret_cast<uint8_t *>(&hei);
	uint32_t	len = wid * hei;
	uint8_t		*lenarr = reinterpret_cast<uint8_t *>(&len);

	uint8_t data[] = {

        // The 8 byte signature, this basically says "I am a png file"
        0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A,

        /************* IHDR chunk *************/
        0x00, 0x00, 0x00, 0x0D, // Length
        0x49, 0x48, 0x44, 0x52, // Type/Name

        // ----- Chunk Data -----
        widarr[3], widarr[2], widarr[1], widarr[0], // Width
        heiarr[3], heiarr[2], heiarr[1], heiarr[0], // Height
        0x01, // Bit Depth
        0x00, // Color Type
        0x00, // Compression Method
        0x00, // Filter Method
        0x00, // Interlace Method
        // ----------------------

        0x90, 0x77, 0x53, 0xDE, // CRC/Checksum
        /**************************************/


        /************* IDAT chunk *************/
        0x00, 0x00, 0x00, 0x0C, // Length
        0x49, 0x44, 0x41, 0x54, // Type/Name

        // ----- Chunk Data -----
        0x08, 0xD7, 0x63, 0xF8,
        0xCF, 0xC0, 0x00, 0x00,
        0x03, 0x01, 0x01, 0x00,
        // ----------------------

        0x18, 0xDD, 0x8D, 0xB0, // CRC/Checksum
        /**************************************/

        /************* IDAT chunk *************/
        lenarr[3], lenarr[2], lenarr[1], lenarr[0], // Length
        0x49, 0x44, 0x41, 0x54, // Type/Name

    };
	return std::vector<uint8_t>(data, data + sizeof(data)/sizeof(data[0]));
}

static std::vector<uint8_t>	getPngEnd()
{
	uint8_t data[] = {
        //end of previous chunk
		0x18, 0xDD, 0x8D, 0xB0, // CRC/Checksum
        /**************************************/

        /************* IEND chunk *************/
        0x00, 0x00, 0x00, 0x00, // Length
        0x49, 0x45, 0x4E, 0x44, // Type/Name
        // ----- Chunk Data -----
        // No Data since length is 0
        // ----------------------
        0xAE, 0x42, 0x60, 0x82 // CRC/Checksum
        /**************************************/

    };
	return std::vector<uint8_t>(data, data + sizeof(data)/sizeof(data[0]));
}

//merci Christopher A
void	Graph::outputImage()
{
	std::ofstream				image("image.png");
	std::vector<uint8_t>		data;
	std::set<Vector2>::iterator	it = points.begin();
	Vector2						pos;

	if (!image)
		throw std::runtime_error("cannot open image");
	data = getPngStart(static_cast<uint32_t>(size.x), static_cast<uint32_t>(size.y));
	for (; pos.y < size.y; ++pos.y)
	{
		for (pos.x = 0; pos.x < size.x; ++pos.x)
		{
			if (it == points.end() || pos < *it)
				data.push_back(0xFF);
			else
			{
				data.push_back(0x00);
				++it;
			}
		}
	}
	std::vector<uint8_t>	tmp = getPngEnd();
	data.insert(data.end(), tmp.begin(), tmp.end());
	image.write(reinterpret_cast<const char*>(data.data()), data.size());
}
