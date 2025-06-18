#include <iostream>
#include <stdexcept>
#include "Forms.hpp"
#include "Secretary.hpp"

Form*	Secretary::createForm(FormType formType)
{
	switch (formType)
	{
		case FormType::NeedMoreClassroom:
			return new NeedMoreClassroomForm;
		case FormType::CourseFinished:
			return new CourseFinishedForm;
		case FormType::NeedCourseCreation:
			return new NeedCourseCreationForm;
		case FormType::SubscriptionToCourse:
			return new SubscriptionToCourseForm;
		default:
			throw std::invalid_argument("unknown form");
	}
}
