#ifndef FORMS_HPP
# define FORMS_HPP

#include <string>
#include "Form.hpp"

class Course;
class Student;
class Classroom;

class CourseFinishedForm : public Form
{
	private:
		Course		*course;
		
		void	_execute();

	public:
		CourseFinishedForm();

		void	setCourse(Course *c);
};

class NeedCourseCreationForm : public Form
{
	private:
		std::string	name;
		Classroom	*classroom;

		void	_execute();//creer course mettre dans classroom
		//name et classroom

	public:
		NeedCourseCreationForm();

		void	setClassroom(Classroom *c);
		void	setName(const std::string &s);
};

class NeedMoreClassroomForm : public Form
{
	private:
		void	_execute();

	public:
		NeedMoreClassroomForm();
};

class SubscriptionToCourseForm : public Form
{
	private:
		Course	*course;
		Student	*student;

		void	_execute();

	public:
		SubscriptionToCourseForm();
		void	setCourse(Course *c);
		void	setStudent(Student *c);
};

#endif
