#include "Employee.hpp"

unsigned	Employee::globalId = 0;

Employee::Employee(const std::string &name, unsigned n) :
	id(Employee::globalId++),
	name(name),
	hourlyValue(n)
{
}

bool	Employee::operator==(const Employee &e)
{
	return id == e.id;
}

bool	Employee::operator<(const Employee &e)
{
	return id < e.id;
}

bool	Employee::operator>(const Employee &e)
{
	return id > e.id;
}
