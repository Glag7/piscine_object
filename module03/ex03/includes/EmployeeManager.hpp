#ifndef EMPLOYEEMANAGER_HPP
# define EMPLOYEEMANAGER_HPP

#include <map>

class Employee;

class EmployeeManager
{
	private:
		std::map<Employee *, unsigned>	employees;

	public:
		EmployeeManager();

		void	addEmployee(Employee *e);
		void	removeEmployee(Employee *e);
		void	executeWorkDay();
		void	calculatePayroll();
};

#endif
