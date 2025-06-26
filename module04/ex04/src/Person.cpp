#include <iostream>
#include "Person.hpp"
#include "Room.hpp"

Person::Person(const std::string &name) :
	name(name),
	currentRoom(nullptr)
{
	std::cout << "Person " << name << " created\n";
}

void	Person::exitRoom()
{
	if (currentRoom == nullptr)
		return;
	std::cout << name << " exited room " << currentRoom->getId() << "\n";
	currentRoom->exit(this);
	currentRoom = nullptr;
}

void	Person::changeRoom(Room *r)
{
	if (r == currentRoom)
		return;
	if (r != nullptr && !r->canEnter(this))
	{
		std::cout << name << " couldn't enter room " << r->getId() << "\n";
		return;
	}
	exitRoom();
	if (r == nullptr)
		return;
	std::cout << name << " entered room " << r->getId() << "\n";
	r->enter(this);
	currentRoom = r;
}
