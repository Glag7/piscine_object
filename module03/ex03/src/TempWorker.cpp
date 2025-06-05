#include "TempWorker.hpp"

TempWorker(const std::string &name, unsigned n) : Employee(name, n),
	workedHours(0)
{
}

void	TempWorker::addWorkedHours(unsigned hours)
{
	workedHours += hours;
}

unsigned	TempWorker::executeWorkDay()
{
	if (workedHours > 7)
	{
		workedHours -= 7;
		return 7 * hourlyValue;
	}

	unsigned tmp = workedHours * hourlyValue;

	workedHours = 0;
	return tmp;
}
