#ifndef ILOGGER_HPP
# define ILOGGER_HPP

#include <string>

class ILogger
{
	public:
		virtual ~ILogger() {}

		virtual void	write(const std::string &s) = 0;
};

#endif
