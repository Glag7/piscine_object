#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <vector>
#include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
	private:
		std::vector<Course*>	_subscribedCourse;

	public:
		Student(const std::string& name) : Person(name) {}

		void	attendClass(Classroom* classroom);
		void	exitClass();
		void	graduate(Course* course);
		void	addCourse(Course* course) {_subscribedCourse.push_back(course);}
};


#endif
