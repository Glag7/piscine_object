#include <stdexcept>
#include <iostream>
#include "Form.hpp"
#include "Headmaster.hpp"

Form::Form(FormType formType) :
	_formType(formType),
	isSigned(false),
	isFilled(false)
{
	std::cout << "creating form\n";
}

void	Form::sign(FormAccess)
{
	if (isFilled)
		isSigned = true;
	throw std::runtime_error("form not filled");
}

void	Form::execute()
{
	if (isSigned)
		_execute();
	throw std::runtime_error("form not signed");
}
