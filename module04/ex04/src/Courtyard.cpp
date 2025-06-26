#include <iostream>
#include "Courtyard.hpp"
#include "Person.hpp"
#include "Student.hpp"

Courtyard::Courtyard() : Room()
{
	std::cout << "Courtyard created with id " << getId() << "\n";
}

bool	Courtyard::canEnter(Person* p)
{
	return dynamic_cast<Student *>(p) != nullptr;
}
