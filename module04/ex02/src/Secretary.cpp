#include <iostream>
#include <stdexcept>
#include "Forms.hpp"
#include "Secretary.hpp"
#include "SecretarialOffice.hpp"

Secretary::Secretary() : Person("secretary")
{
	std::cout << "Secretary created\n";
}

Form*	Secretary::createForm(FormType formType)
{
	if (dynamic_cast<SecretarialOffice *>(currentRoom) == nullptr)
	{
		throw std::logic_error("couldn't create form outside office");
	}

	Form	*form;

	switch (formType)
	{
		case FormType::NeedMoreClassroom:
			form = new NeedMoreClassroomForm;
			break;
		case FormType::CourseFinished:
			form = new CourseFinishedForm;
			break;
		case FormType::NeedCourseCreation:
			form = new NeedCourseCreationForm;
			break;
		case FormType::SubscriptionToCourse:
			form = new SubscriptionToCourseForm;
			break;
		default:
			throw std::invalid_argument("unknown form");
	}
	std::cout << "Secretary created form\n";
	dynamic_cast<SecretarialOffice *>(currentRoom)->addForm(form);
	return form;
}
