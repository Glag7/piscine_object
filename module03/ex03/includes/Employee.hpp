#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

#include <string>

class Employee
{
	private:
		static unsigned	globalId;

		unsigned	id;
		unsigned	hourlyValue;
		std::string	name;

	public:
		Employee(const std::String &name, unsigned n);
		virtual ~Employee {}

		virtual unsigned	executeWorkDay() = 0;
};

#endif
