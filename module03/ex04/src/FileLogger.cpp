#include <stdexcept>
#include "FileLogger.hpp"

FileLogger::FileLogger(const std::string &filename) :
	filename(filename),
	header(nullptr)
{
}

FileLogger::FileLogger(const std::string &filename, IHeader *header) :
	filename(filename),
	header(header)
{
}

void	FileLogger::write(const std::string &s)
{
	std::ofstream	file(filename, std::ios::app);

	if (!file)
		throw std::runtime_error("EPIC FILELOGGER FAIL\n");
	if (header != nullptr)
		header->outputHeader(file);
	file << s;
}
