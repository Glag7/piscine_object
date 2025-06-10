#ifndef ROOM_HPP
# define ROOM_HPP

#include <vector>

class Person;

class Room
{
	private:
		long long				id;
		std::vector<Person*>	_occupants;

	public:
		Room();

		bool	canEnter(Person* p);
		void	enter(Person* p);
		void	exit(Person* p);
		void	printOccupant();
};


#endif
