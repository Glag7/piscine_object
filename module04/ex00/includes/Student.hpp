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
		void	attendClass(Classroom* classroom);
		void	exitClass();
		void	graduate(Course* course);
};


#endif
