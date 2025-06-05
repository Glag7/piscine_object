#include <iostream>
#include <vector>
#include "ILogger.hpp"
#include "StreamLogger.hpp"
#include "FileLogger.hpp"
#include "DateHeader.hpp"
#include "StringHeader.hpp"

int	main()
{
	std::vector<ILogger *>	loggers;
	DateHeader		dh;
	StringHeader	sh("wow: ");
	StreamLogger	a(std::cout); loggers.push_back(&a);
	StreamLogger	b(std::cout, &dh); loggers.push_back(&b);
	StreamLogger	c(std::cout, &sh); loggers.push_back(&c);
	FileLogger		d("/dev/stdout"); loggers.push_back(&d);
	FileLogger		e("/dev/stdout", &dh); loggers.push_back(&e);
	FileLogger		f("/dev/stdout", &sh); loggers.push_back(&f);

	for (auto log : loggers)
	{
		try
		{
			log->write("skibidi sigma\n");
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Message from logger: " << e.what() << "\n";
		}
	}
}
