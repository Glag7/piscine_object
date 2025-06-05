#ifndef TEMPWORKER_HPP
# define TEMPWORKER_HPP

#include "Employee.hpp"
#include "HourlyEmployee.hpp"

class TempWorker : public Employee, public HourlyEmployee
{
	private:
		unsigned	workedHours;

	public:
		TempWorker(const std::string &name, unsigned n);

		void		addWorkedHours(unsigned hours);
		unsigned	executeWorkDay();
};

#endif
