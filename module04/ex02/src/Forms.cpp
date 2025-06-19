#include <stdexcept>
#include <iostream>
#include "Forms.hpp"
#include "Singleton.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Student.hpp"

CourseFinishedForm::CourseFinishedForm() :
	Form(FormType::CourseFinished),
	course(nullptr),
	student(nullptr)
{
	std::cout << "Created course finished form\n";
}

void	CourseFinishedForm::_execute()
{
	std::cout << "Executed course finished form\n";
	std::cout << "course " << course->getName() << " student " << student->getName() << "\n";
}

void	CourseFinishedForm::fill(Course *c, Student *s)
{
	if (c == NULL || s == NULL)
		throw std::logic_error("...");
	course = c;
	student = s;
	isFilled = true;
}

//===

NeedCourseCreationForm::NeedCourseCreationForm() :
	Form(FormType::NeedCourseCreation),
	name(""),
	classroom(0)
{
	std::cout << "Created need course creation form\n";
}

void	NeedCourseCreationForm::fill(Classroom *c, const std::string &s)
{
	if (c == NULL || s == "")
		throw std::logic_error("...");
	classroom = c;
	name = s;
	isFilled = true;
}

void	NeedCourseCreationForm::_execute()
{
	std::cout << "Executed need course creation form\n";
	Course	*c = new Course(name);

	classroom->assignCourse(c);
	SSet<Course *>::getInstance().insert(c);
}

//===

NeedMoreClassroomForm::NeedMoreClassroomForm() : Form(FormType::NeedMoreClassroom)
{
	isFilled = true;
	std::cout << "Created need more classrooms form\n";
}

void	NeedMoreClassroomForm::_execute()
{
	std::cout << "Executed need more classroom form\n";
	SSet<Room *>::getInstance().insert(new Classroom);
}

//===

SubscriptionToCourseForm::SubscriptionToCourseForm() :
	Form(FormType::SubscriptionToCourse),
	course(0),
	student(0)
{
	std::cout << "Created subscription to course form\n";
}

void	SubscriptionToCourseForm::fill(Course *c, Student *s)
{
	if (c == NULL || s == NULL)
		throw std::logic_error("...");
	course = c;
	student = s;
	isFilled = true;
}

void	SubscriptionToCourseForm::_execute()
{
	std::cout << "Executed subscription to course form\n";
	student->addCourse(course);
}
