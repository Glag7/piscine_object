#include <iostream>
#include <stdexcept>
#include "Headmaster.hpp"
#include "HeadmasterOffice.hpp"
#include "Form.hpp"

Headmaster::Headmaster() : Person("headmaster")
{
	std::cout << "Headmaster created\n";
}

void Headmaster::receiveForm(Form* form)
{
	std::cout << "Headmaster received form\n";
	formsToSign.insert(form);
}

void	Headmaster::signForm(Form *form)
{
	if (dynamic_cast<HeadmasterOffice *>(currentRoom) == nullptr)
	{
		throw std::logic_error("couldn't sign form outside office");
	}
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
		std::cout << "Headmaster was unable to sign form : " << e.what() << "\n";
	}
}

void	Headmaster::signAllForms()
{
	auto	it = formsToSign.begin();

	while (it != formsToSign.end())
	{
		Form	*form = *it;

		++it;
		signForm(form);
	}
}
