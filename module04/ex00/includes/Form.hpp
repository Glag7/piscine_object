#ifndef FORM_HPP
# define FORM_HPP

enum class FormType
{
	CourseFinished,
	NeedMoreClassroom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
	private:
		FormType	_formType;

	public:
		Form(FormType formType);

		virtual void	execute() = 0;
};


#endif
