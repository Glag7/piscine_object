#ifndef ROOM_HPP
# define ROOM_HPP

#include <set>

class Person;

class Room
{
	private:
		static long long	globalId;

		long long			id;
		std::set<Person *>	people;

	public:
		Room();
		virtual ~Room() {}

		long long	getId() const {return id;}
		unsigned	getN() const {return people.size();}

		virtual bool	canEnter(Person* p) = 0;
		void			enter(Person* p);
		void			exit(Person* p);
		void			printOccupants();
};


#endif
