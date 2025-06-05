#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

class HourlyEmployee 
{
	public:
		virtual	~HourlyEmployee() {}

		virtual void	addWorkedHours(unsigned hours) = 0;
};

#endif
