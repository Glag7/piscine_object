#ifndef CRC_HPP
# define CRC_HPP

uint32_t crc32(const std::vector<uint8_t>& data);
uint32_t adler32(const std::vector<uint8_t>& data);

#endif
