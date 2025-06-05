#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

class SalariedEmployee
{
	public:
		virtual	~SalariedEmployee() {}

		virtual void	addUnworkedHours(unsigned hours) = 0;
};

#endif
