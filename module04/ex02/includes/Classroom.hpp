#ifndef CLASSROOM_HPP
# define CLASSROOM_HPP

#include "Room.hpp"

class Course;

class Classroom : public Room
{
	private:
		Course*	_currentRoom;

	public:
		Classroom() : Room() {}

		void	assignCourse(Course* course);
};

#endif
