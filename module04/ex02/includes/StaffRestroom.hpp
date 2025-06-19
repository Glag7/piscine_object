#ifndef STAFFRESTROOM_HPP
# define STAFFRESTROOM_HPP

#include "Room.hpp"

class Person;

class StaffRestroom : public Room
{
	public:
		StaffRestroom();

		bool	canEnter(Person* p);

};

#endif
