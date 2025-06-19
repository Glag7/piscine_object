#include <iostream>
#include "Professor.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

Professor::Professor(const std::string &s) :
	Person(s),
	currentCourse(nullptr)
{
	std::cout << "Professor " << getName() << " created\n";
}

void	Professor::assignCourse(Course* course)
{
	if (currentCourse)
	{
		std::cout << "Professor " << getName() << " left course " << currentCourse->getName() << "\n";
		currentCourse->assign(nullptr);
		exitRoom();
	}
	currentCourse = course;
	if (course)
	{
		std::cout << "Professor " << getName() << " joined course " << currentCourse->getName() << "\n";
		currentCourse->assign(this);
		changeRoom(currentCourse->getRoom());
	}
}

void	Professor::doClass()
{
	//verifier que la course est valide avec classroom
	std::cout << "do something\n";
}

void	Professor::closeCourse()
{
	//verifier que la course est valide avec classroom
	std::cout << "do something\n";
}
