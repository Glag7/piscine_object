#include <iostream>
#include "Car.hpp"

int main()
{
	Car	car(4, 100, 60, 30);

	car.accelerate(30);
	car.start();
	car.accelerate(3000000);
	car.accelerate(50);
	car.stop();
	car.start();
	car.apply_force_on_brakes(31);
	car.apply_force_on_brakes(30);
	car.accelerate(50);
	car.reverse();
	car.shift_gears_down();
	car.shift_gears_up();
	car.shift_gears_down();
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up();
	car.shift_gears_up();
	car.turn_wheel(90);
	car.turn_wheel(15);
	car.turn_wheel(40);
	car.straighten_wheels();
	car.apply_emergency_brakes();
	car.stop();
}
