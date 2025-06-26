#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

#include <set>
#include "Person.hpp"

class Form;

class Headmaster : public Person
{
	private:
		std::set<Form *>	formsToSign;
		
	public:
		Headmaster();

		void	receiveForm(Form* form);
		void	signForm(Form *form);
		void	signAllForms();
		void	attendClasses();
};


#endif
