#ifndef PERSON_HPP
# define PERSON_HPP

#include <string>

class Room;

class Person
{
	protected:
		std::string	name;
		Room*		currentRoom;

	public:
		Person(const std::string &name);
		virtual ~Person() {}

		const std::string	&getName() const {return name;}
		const Room			*getRoom() const {return currentRoom;}

		void	exitRoom();
		void	changeRoom(Room *r);
};

#endif
