#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

class SalariedEmployee
{
	public:
		SalariedEmployee();
		virtual	~SalariedEmployee();

		void	addUnworkedHours(unsigned hours) = 0;
};

#endif
