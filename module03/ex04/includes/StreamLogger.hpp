#ifndef STREAMLOGGER_HPP
# define STREAMLOGGER_HPP

#include <ostream>
#include <string>
#include "ILogger.hpp"
#include "IHeader.hpp"

class StreamLogger : public ILogger
{
	private:
		std::ostream	&stream;
		IHeader			*header;

	public:
		StreamLogger(std::ostream &stream);
		StreamLogger(std::ostream &stream, IHeader *header);

		void	write(const std::string &s);
};

#endif
