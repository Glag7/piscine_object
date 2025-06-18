#ifndef PERSON_HPP
# define PERSON_HPP

#include <string>

class Room;

class Person
{
	private:
		std::string	_name;
		Room*		_currentRoom;

	public:
		Person(const std::string &name) : _name(name) {}

		const std::string	&getName() {return _name;}

		const Room*	room() {return _currentRoom;}
};


#endif
