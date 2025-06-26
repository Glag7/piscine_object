#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <map>
#include "Person.hpp"
#include "Observer.hpp"

class Course;
class Classroom;

class Student : public Person, public Observer
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
		void	receive(Event e);
};


#endif
