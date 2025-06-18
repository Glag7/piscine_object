#include "Forms.hpp"

CourseFinishedForm::CourseFinishedForm() :
	Form(FormType::CourseFinished),
	course(0)
{
}

void	CourseFinishedForm::execute()
{
	delete course;
}

void	CourseFinishedForm::setCourse(Course *c)
{
	course = c;
	isFilled = true;
}
