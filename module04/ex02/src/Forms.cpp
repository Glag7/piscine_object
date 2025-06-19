#include <set>
#include <stdexcept>
#include <iostream>
#include "Forms.hpp"
#include "Singleton.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Student.hpp"

CourseFinishedForm::CourseFinishedForm() :
	Form(FormType::CourseFinished),
	course(0)
{
	std::cout << "Creating course finished form\n";
}

void	CourseFinishedForm::_execute()
{
	std::set<Course *>	&courseList = SSet<Course *>::getInstance();
	auto				it = courseList.find(course);

	if (it == courseList.end())
		throw std::logic_error("...");
	courseList.erase(it);
	delete course;
}

void	CourseFinishedForm::setCourse(Course *c)
{
	if (c == NULL)
		throw std::logic_error("...");
	course = c;
	isFilled = true;
}

//===

NeedCourseCreationForm::NeedCourseCreationForm() :
	Form(FormType::NeedCourseCreation),
	name(""),
	classroom(0)
{
	std::cout << "Creating need course creation form\n";
}

void	NeedCourseCreationForm::setClassroom(Classroom *c)
{
	if (c == NULL)
		throw std::logic_error("...");
	classroom = c;
	isFilled = name != "";
}

void	NeedCourseCreationForm::setName(const std::string &s)
{
	if (s == "")
		throw std::logic_error("...");
	name = s;
	isFilled = classroom != NULL;
}

void	NeedCourseCreationForm::_execute()
{
	Course	*c = new Course(name);

	classroom->assignCourse(c);
	SSet<Course *>::getInstance().insert(c);
}

//===

NeedMoreClassroomForm::NeedMoreClassroomForm() : Form(FormType::NeedMoreClassroom)
{
	isFilled = true;
	std::cout << "Creating need more classrooms form\n";
}

void	NeedMoreClassroomForm::_execute()
{
	SSet<Room *>::getInstance().insert(new Classroom);
}

//===

SubscriptionToCourseForm::SubscriptionToCourseForm() :
	Form(FormType::SubscriptionToCourse),
	course(0),
	student(0)
{
	std::cout << "Creating subscription to course form\n";
}

void	SubscriptionToCourseForm::setCourse(Course *c)
{
	if (c == NULL)
		throw std::logic_error("...");
	course = c;
	isFilled = student != NULL;
}

void	SubscriptionToCourseForm::setStudent(Student *c)
{
	if (c == NULL)
		throw std::logic_error("...");
	student = c;
	isFilled = course != NULL;
}

void	SubscriptionToCourseForm::_execute()
{
	course->subscribe(student);
	student->addCourse(course);
}
