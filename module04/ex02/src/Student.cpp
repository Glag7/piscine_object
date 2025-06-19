#include <iostream>
#include <stdexcept>
#include "Student.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

Student::Student(const std::string& name) : Person(name)
{
	std::cout << "Student " << name << " created\n";
}

void	Student::attendClass(Classroom* classroom)
{
	(void)classroom;
	std::cout << "do something\n";//check course + prof + go to room
}

void	Student::exitClass()
{
	std::cout << "do something\n";//wtf does this do
}

void	Student::graduate(Course* course)
{
	(void)course;
	std::cout << "do something\n";
}

void	Student::addCourse(Course* course)
{
	if (course == nullptr)
		throw std::logic_error("...");
	std::cout << "Student " << getName() << " joined course " << course->getName() << "\n";
	subscribedCourses.insert(course);
	course->subscribe(this);
}
