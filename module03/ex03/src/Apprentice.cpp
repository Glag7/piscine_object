#include "Apprentice.hpp"
		
Apprentice::Apprentice(const std::string &name, unsigned n) : Employee(name, n),
	unworkedHours(0),
	schoolHours(0)
{
}

void	Apprentice::addWorkedHours(unsigned hours)
{
	schoolHours += hours;
}

void	Apprentice::addUnworkedHours(unsigned hours)
{
	unworkedHours += hours;
}

unsigned	Apprentice::executeWorkDay()
{
	if (unworkedHours > 7)
	{
		unworkedHours -= 7;
		return 0;
	}

	unsigned	remainingHours = 7 - unworkedHours;
	unsigned	pay = 0;

	unworkedHours = 0;
	if (schoolHours > remainingHours)
	{
		pay = remainingHours * hourlyValue * .5;
		schoolHours -= (remainingHours - unworkedHours);
		unworkedHours = 0;
		return pay;
	}
	pay += schoolHours * hourlyValue * .5;
	remainingHours -= schoolHours;
	schoolHours = 0;
	return pay + remainingHours * hourlyValue;
}
