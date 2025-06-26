#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <map>
#include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
	private:
		std::map<Course *, unsigned>	subscribedCourses;

	public:
		Student(const std::string& name);

		void	findClass();
		void	attendClass(Classroom* classroom);
		bool	doCourse(Course *course);
		void	exitClass();
		void	graduate(Course* course);
		void	addCourse(Course* course);
};


#endif
