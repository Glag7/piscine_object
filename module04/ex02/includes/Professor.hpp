#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

#include <string>
#include "Person.hpp"

class Course;

class Professor : public Person
{
	private:
		Course	*currentCourse;

	public:
		Professor(const std::string &s);

		void	assignCourse(Course* course);
		void	doClass();
		void	closeCourse();
};

#endif
