#include <stdexcept>
#include <iostream>
#include "Form.hpp"
#include "Headmaster.hpp"

Form::Form(FormType formType) :
	_formType(formType),
	isSigned(false),
	isFilled(false)
{
	std::cout << "Created form\n";
}

void	Form::sign(FormAccess)
{
	if (isFilled)
		isSigned = true;
	else
		throw std::runtime_error("form not filled");
}

void	Form::execute()
{
	if (isSigned)
	{
		std::cout << "Executed form\n";
		_execute();
	}
	else
		throw std::runtime_error("form not signed");
}
