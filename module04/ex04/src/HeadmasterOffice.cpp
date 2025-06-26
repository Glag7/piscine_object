#include <iostream>
#include "HeadmasterOffice.hpp"
#include "Person.hpp"
#include "Headmaster.hpp"

HeadmasterOffice::HeadmasterOffice() : Room()
{
	std::cout << "Headmaster office created with id " << getId() << "\n";
}

bool	HeadmasterOffice::canEnter(Person* p)
{
	return dynamic_cast<Headmaster *>(p) != nullptr;
}
