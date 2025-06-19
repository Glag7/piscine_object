#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <set>
#include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
	private:
		std::set<Course *>	subscribedCourses;

	public:
		Student(const std::string& name);

		void	attendClass(Classroom* classroom);
		void	exitClass();
		void	graduate(Course* course);
		void	addCourse(Course* course);
};


#endif
