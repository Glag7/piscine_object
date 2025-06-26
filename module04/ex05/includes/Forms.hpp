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
		Student		*student;
		
		void	_execute();

	public:
		CourseFinishedForm();

		void	fill(Course *c, Student *s);
};

class NeedCourseCreationForm : public Form
{
	private:
		std::string	name;

		void	_execute();

	public:
		NeedCourseCreationForm();

		void	fill(const std::string &s);
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
		void	fill(Course *c, Student *s);
};

#endif
