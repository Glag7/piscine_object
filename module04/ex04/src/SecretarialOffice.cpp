#include <iostream>
#include "SecretarialOffice.hpp"
#include "Secretary.hpp"
#include "Form.hpp"

SecretarialOffice::SecretarialOffice() : Room()
{
	std::cout << "Secretarial office created with id " << getId() << "\n";
}

SecretarialOffice::~SecretarialOffice()
{
	for (Form *form : archivedForms)
		delete form;
}

bool	SecretarialOffice::canEnter(Person* p)
{
	return dynamic_cast<Secretary *>(p) != NULL;
}

void	SecretarialOffice::addForm(Form *f)
{
	std::cout << "Archived form\n";
	archivedForms.insert(f);
}
