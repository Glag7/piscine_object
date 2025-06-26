#ifndef HEADMASTEROFFICE_HPP
# define HEADMASTEROFFICE_HPP

#include "Room.hpp"

class Person;

class HeadmasterOffice : public Room
{
	public:
		HeadmasterOffice();

		bool	canEnter(Person* p);
};

#endif
