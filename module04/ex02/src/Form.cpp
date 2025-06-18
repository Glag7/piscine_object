#include <stdexcept>
#include "Form.hpp"
#include "Headmaster.hpp"

Form::Form(FormType formType) :
	_formType(formType),
	isSigned(false),
	isFilled(false)
{
}

void	Form::sign()
{
	isSigned = true;
}

void	Form::sign(FormAccess)
{
	if (isFilled)
		sign();
	throw std::runtime_error("form not filled");
}

void	Form::execute(FormAccess)
{
	if (isSigned)
		execute();
	throw std::runtime_error("form not signed");
}
