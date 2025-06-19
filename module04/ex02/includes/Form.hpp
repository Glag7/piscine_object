#ifndef FORM_HPP
# define FORM_HPP

class Headmaster;

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
		bool		isSigned;
	
	protected:
		bool		isFilled;
		
		virtual void	_execute() = 0;

	public:
		Form(FormType formType);

		FormType	getFormType() const {return _formType;}

		class	FormAccess
		{
			private:
				FormAccess() = default;
				friend class Headmaster;
		};

		void	sign(FormAccess);
		void	execute();
};


#endif
