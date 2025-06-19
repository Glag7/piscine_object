#include <iostream>
#include "StaffRestroom.hpp"
#include "Professor.hpp"
#include "Headmaster.hpp"
#include "Secretary.hpp"


StaffRestroom::StaffRestroom()
{
	std::cout << "Staff restroom created with id " << getId() << "\n";//i dont choose class names
}

bool	StaffRestroom::canEnter(Person* p)
{
	return dynamic_cast<Headmaster *>(p) != nullptr
			|| dynamic_cast<Secretary *>(p) != nullptr
			|| dynamic_cast<Professor *>(p) != nullptr;
}
