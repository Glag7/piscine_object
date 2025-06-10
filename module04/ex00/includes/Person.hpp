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
		Person(std::string name);

		const Room*	room() {return _currentRoom;}
};


#endif
