#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

#include <string>
#include "Person.hpp"
#include "Observer.hpp"

class Course;

class Professor : public Person, public Observer
{
	private:
		Course	*currentCourse;

	public:
		Professor(const std::string &s);

		void	assignCourse(Course* course);
		void	findClass();
		void	findRoom();
		void	doClass();
		void	receive(Event e);
};

#endif
