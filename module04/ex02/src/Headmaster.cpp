#include <iostream>
#include "Headmaster.hpp"
#include "Form.hpp"

void Headmaster::receiveForm(Form* form)
{
	std::cout << "Headmaster received form\n";
	formsToSign.insert(form);
}

void	Headmaster::signForm(Form *form)
{
	try
	{
		form->sign(Form::FormAccess());
		std::cout << "Headmaster signed form\n";
		auto	it = formsToSign.find(form);
		if (it != formsToSign.end())
			formsToSign.erase(it);
	}
	catch (std::exception &e)
	{
		std::cout << "Headmaster unable to sign form : " << e.what() << "\n";
	}
}

void	Headmaster::signAllForms()
{
	auto	it = formsToSign.begin();

	std::cout << "Headmaster signing all forms\n";
	while (it != formsToSign.end())
	{
		Form	*form = *it;

		++it;
		signForm(form);
	}
}
