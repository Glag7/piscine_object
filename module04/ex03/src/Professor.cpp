#include <iostream>
#include "Professor.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "Singleton.hpp"
#include "Forms.hpp"
#include "Form.hpp"
#include "Student.hpp"

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
	}
	currentCourse = course;
	if (course)
	{
		std::cout << "Professor " << getName() << " joined course " << currentCourse->getName() << "\n";
		currentCourse->assign(this);
	}
}

void	Professor::findClass()
{
	for (Course *c : SSet<Course *>::getInstance())
	{
		if (c->hasTeacher())
			continue;
		assignCourse(c);
		return;
	}
}

void	Professor::findRoom()
{
	for (Room *r : SSet<Room *>::getInstance())
	{
		Classroom	*c = dynamic_cast<Classroom *>(r);
		if (c == nullptr || c->getN() != 0)
			continue;
		c->assignCourse(currentCourse);
		changeRoom(c);
		return;
	}
}

void	Professor::doClass()
{
	if (currentCourse == nullptr)
		findClass();
	if (currentCourse == nullptr)
	{
		std::cout << "Professor " << name << " had no class\n";
		NeedCourseCreationForm	*form = dynamic_cast<NeedCourseCreationForm *>(Singleton<Secretary>::getInstance().createForm(FormType::NeedCourseCreation));
		form->fill(name + "_course");
		Singleton<Headmaster>::getInstance().signForm(form);
		form->execute();
		findClass();
	}
	if (dynamic_cast<Classroom *>(currentRoom) == nullptr)
		findRoom();
	if (dynamic_cast<Classroom *>(currentRoom) == nullptr)
	{
		std::cout << "Professor " << name << " found no classroom\n";
		NeedMoreClassroomForm	*form = dynamic_cast<NeedMoreClassroomForm *>(Singleton<Secretary>::getInstance().createForm(FormType::NeedMoreClassroom));
		Singleton<Headmaster>::getInstance().signForm(form);
		form->execute();
		findRoom();
	}
	currentCourse->moveStudents(dynamic_cast<Classroom *>(currentRoom));
	std::cout << "Professor " << name << " taught course " << currentCourse->getName() << "\n";
	
	std::set<Student *>	grad;
	for (Student *s : currentCourse->getStudents())
	{
		if (s->doCourse(currentCourse))
			grad.insert(s);
	}
	for (Student *s : grad)
	{
		std::cout << "Professor " << name << " graduated student " << s->getName() << " on course " << currentCourse->getName() << "\n";
		CourseFinishedForm	*form = dynamic_cast<CourseFinishedForm *>(Singleton<Secretary>::getInstance().createForm(FormType::CourseFinished));
		form->fill(currentCourse, s);
		Singleton<Headmaster>::getInstance().signForm(form);
		form->execute();
	}
}
