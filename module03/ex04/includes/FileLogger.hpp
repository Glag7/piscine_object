#ifndef FILELOGGER_HPP
# define FILELOGGER_HPP

#include <fstream>
#include <string>
#include "ILogger.hpp"
#include "IHeader.hpp"

class FileLogger : public ILogger
{
	private:
		std::string		filename;
		IHeader			*header;

	public:
		FileLogger(const std::string &filename);
		FileLogger(const std::string &filename, IHeader *header);

		void	write(const std::string &s);
};

#endif
