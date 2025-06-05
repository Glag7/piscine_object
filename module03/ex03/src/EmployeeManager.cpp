#include <iostream>
#include "EmployeeManager.hpp"
#include "Employee.hpp"

EmployeeManager::EmployeeManager()
{
}

void	EmployeeManager::addEmployee(Employee *e)
{
	employees[e] += 0;
}

void	EmployeeManager::removeEmployee(Employee *e)
{
	auto	it = employees.find(e);

	if (it != employees.end())
		employees.erase(it);
}

void	EmployeeManager::executeWorkDay()
{
	for (auto &it : employees)
		it.second += it.first->executeWorkDay();
}

void	EmployeeManager::calculatePayroll()
{
	for (auto it : employees)
		std::cout << it.first->getName() << " gets paid " << it.second << "\n";
}
