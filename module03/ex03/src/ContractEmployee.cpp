#include "ContractEmployee.hpp"
		
ContractEmployee::ContractEmployee(const std::string &name, unsigned n) : Employee(name, n),
	unworkedHours(0)
{
}

void	ContractEmployee::addUnworkedHours(unsigned hours)
{
	unworkedHours += hours;
}

unsigned	ContractEmployee::executeWorkDay()
{
	if (unworkedHours > 7)
	{
		unworkedHours -= 7;
		return 0;
	}

	unsigned tmp = (7 - unworkedHours) * hourlyValue;

	unworkedHours = 0;
	return tmp;
}
