#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

class HourlyEmployee 
{
	public:
		HourlyEmployee();
		virtual	~HourlyEmployee();

		void	addWorkedHours(unsigned hours) = 0;
};

#endif
