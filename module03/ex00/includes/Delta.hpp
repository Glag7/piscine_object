#ifndef DELTA_HPP
# define DELTA_HPP

#include <chrono>

class Delta
{
	private:
		std::chrono::steady_clock::time_point	prevTime;
		double									delta;
		
		Delta();

	public:
		static Delta	&getInstance();

		Delta(const Delta &delta) = delete;
		void	operator=(const Delta &delta) = delete;

		double	getDelta() const {return delta;}

		double	updateDelta();
};

#endif
