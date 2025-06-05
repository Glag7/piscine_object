#include "StreamLogger.hpp"

StreamLogger::StreamLogger(std::ostream &stream) :
	stream(stream),
	header(nullptr)
{
}

StreamLogger::StreamLogger(std::ostream &stream, IHeader *header) :
	stream(stream),
	header(header)
{
}

void	StreamLogger::write(const std::string &s)
{
	if (header != nullptr)
		header->outputHeader(stream);
	stream << s;
}
