#ifndef COURTYARD_HPP
# define COURTYARD_HPP

#include "Room.hpp"

class Person;

class Courtyard : public Room
{
	public:
		Courtyard();
		
		bool	canEnter(Person* p);
};

#endif
