#ifndef CONTRACTEMPLOYEE_HPP
# define CONTRACTEMPLOYEE_HPP

#include "Employee.hpp"
#include "SalariedEmployee.hpp"

class ContractEmployee : public Employee, public SalariedEmployee
{
	private:
		unsigned	unWorkedHours;

	public:
		ContractEmployee(const std::string &name, unsigned n);

		void		addUnworkedHours(unsigned hours);	
		unsigned	executeWorkDay();
};

#endif
