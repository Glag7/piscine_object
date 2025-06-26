#ifndef CLASSROOM_HPP
# define CLASSROOM_HPP

#include "Room.hpp"

class Course;
class Person;

class Classroom : public Room
{
	private:
		Course	*currentCourse;

	public:
		Classroom();

		bool	canEnter(Person* p);
		void	assignCourse(Course* course);
};

#endif
