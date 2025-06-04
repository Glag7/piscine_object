#ifndef CAR_HPP
# define CAR_HPP

#include "Engine.hpp"
#include "Transmission.hpp"
#include "Brake.hpp"
#include "Steering.hpp"

class Car
{
	private:
		Engine			engine;
		Transmission	transmission;
		Steering		steering;
		Brake			brakes;

	public:
		Car(unsigned gears, unsigned maxSpeed, unsigned maxAngle, unsigned maxForce);

		void	start();
		void	stop();
		void	accelerate(unsigned speed);
		void	shift_gears_up();
		void	shift_gears_down();
		void	reverse();
		void	turn_wheel(int angle);
		void	straighten_wheels();
		void	apply_force_on_brakes(unsigned force);
		void	apply_emergency_brakes();
};

#endif
