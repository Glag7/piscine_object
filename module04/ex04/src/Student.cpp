#include <iostream>
#include <stdexcept>
#include "Student.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Singleton.hpp"
#include "Secretary.hpp"
#include "Form.hpp"
#include "Forms.hpp"
#include "Headmaster.hpp"

Student::Student(const std::string& name) :
	Person(name),
	Observer(Singleton<Bell>::getInstance())
{
	std::cout << "Student " << name << " created\n";
}

void	Student::findClass()
{
	if (subscribedCourses.size() != 0)
		return;
	std::cout << "Student " << name << " without courses\n";
	for (Course *c : SSet<Course *>::getInstance())
	{
		if (c->isFull())
			continue;
		SubscriptionToCourseForm	*form = dynamic_cast<SubscriptionToCourseForm *>(Singleton<Secretary>::getInstance().createForm(FormType::SubscriptionToCourse));
		form->fill(c, this);
		Singleton<Headmaster>::getInstance().signForm(form);
		form->execute();
		return;
	}
	std::cout << "Student " << name << " could not find a course\n";
}

void	Student::attendClass(Classroom* classroom)
{
	if (classroom == nullptr)
		throw std::logic_error("...");
	changeRoom(classroom);
}

bool	Student::doCourse(Course *course)
{
	auto	it = subscribedCourses.find(course);

	if (it == subscribedCourses.end())
		throw std::logic_error("...");

	std::cout << "Student " << name << " was taught course " << course->getName() << "\n";
	return ++subscribedCourses[course] >= course->getReqAttendance();
}

void	Student::exitClass()
{
	exitRoom();
}

void	Student::graduate(Course* course)
{
	if (course == nullptr)
		throw std::logic_error("...");
	std::cout << "Student " << name << " graduated course " << course->getName() << "\n";

	auto	it = subscribedCourses.find(course);

	if (it == subscribedCourses.end())
		throw std::logic_error("...");
	subscribedCourses.erase(it);
}

void	Student::addCourse(Course* course)
{
	if (course == nullptr)
		throw std::logic_error("...");
	std::cout << "Student " << getName() << " joined course " << course->getName() << "\n";
	subscribedCourses[course] += 0;
}

void	Student::receive(Event e)
{
	if (e == Event::RingBell)
		std::cout << "wow\n";
}
