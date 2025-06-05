#ifndef APPRENTICE_HPP
# define APPRENTICE_HPP

#include "Employee.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"

class Apprentice : public Employee, public HourlyEmployee, public SalariedEmployee
{
	private:
		unsigned	unworkedHours;
		unsigned	schoolHours;

	public:
		Apprentice(const std::string &name, unsigned n);

		void		addWorkedHours(unsigned hours);
		void		addUnworkedHours(unsigned hours);	
		unsigned	executeWorkDay();
};


#endif
