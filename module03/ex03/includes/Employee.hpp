#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

#include <string>

class Employee
{
	protected:
		static unsigned	globalId;

		unsigned	id;
		std::string	name;
		unsigned	hourlyValue;

	public:
		Employee(const std::string &name, unsigned n);
		bool	operator==(const Employee &e);
		bool	operator<(const Employee &e);
		bool	operator>(const Employee &e);
		virtual ~Employee() {}

		const std::string	&getName() {return name;}

		virtual unsigned	executeWorkDay() = 0;
};

#endif
