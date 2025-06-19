#include <iostream>
#include "Classroom.hpp"
#include "Course.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Professor.hpp"

Classroom::Classroom() :
Room(),
currentCourse(nullptr)
{
	std::cout << "Classroom created with id " << getId() << "\n";
}

bool	Classroom::canEnter(Person* p)
{
	return (dynamic_cast<Student *>(p) != nullptr || dynamic_cast<Professor *>(p) != nullptr);
}

void	Classroom::assignCourse(Course* course)
{
	if (currentCourse)
	{
		std::cout << "Room " << getId() << " removed course " << course->getName() << "\n";
		currentCourse->setClassroom(nullptr);
	}
	currentCourse = course;
	if (course)
	{
		std::cout << "Room " << getId() << " course set to " << course->getName() << "\n";
		currentCourse->setClassroom(this);
	}
}
