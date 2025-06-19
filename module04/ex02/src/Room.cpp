#include <iostream>
#include <stdexcept>
#include "Room.hpp"
#include "Person.hpp"

long long	Room::globalId = 0;

Room::Room() : id(Room::globalId++)
{
	std::cout << "Room " << id << " created\n";
}

void	Room::enter(Person* p)
{
	if (p == nullptr)
		throw std::logic_error("...");
	people.insert(p);
	std::cout << "Room " << id << " was entered by " << p->getName() << "\n";
}

void	Room::exit(Person* p)
{
	auto	it = people.find(p);

	if (it == people.end())//also checks null
		throw std::logic_error("...");
	std::cout << "Room " << id << " was left by " << p->getName() << "\n";
	people.erase(it);
}

void	Room::printOccupants()
{
	std::cout << "Room " << id << " occupants:\n";
	for (Person *p : people)
		std::cout << "-" << p->getName() << "\n";
}
