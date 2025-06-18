#ifndef FORMS_HPP
# define FORMS_HPP

#include <string>
#include "Form.hpp"

class CourseFinishedForm : public Form
{
	private:
		Course	*course;
		
		void	execute();//supprimer de la classroom
		//enlever du singleton

	public:
		CourseFinishedForm();

		void	setCourse(Course *c);
};

class NeedCourseCreationForm : public Form
{
	private:
		void	execute();//creer course mettre dans classroom
		//name et classroom

	public:
		NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {}
};

class NeedMoreClassroomForm : public Form
{
	private:
		void	execute();

	public:
		NeedMoreClassroomForm() : Form(FormType::NeedMoreClassroom) {}
};

class SubscriptionToCourseForm : public Form
{
	private:
		void	execute();

	public:
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {}
};

#endif
