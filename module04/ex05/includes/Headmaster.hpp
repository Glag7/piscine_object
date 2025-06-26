#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

#include <set>
#include "Person.hpp"
#include "Bell.hpp"

class Form;

class Headmaster : public Person
{
	private:
		Bell				&bell;
		std::set<Form *>	formsToSign;
		
	public:
		Headmaster();

		void	receiveForm(Form* form);
		void	signForm(Form *form);
		void	signAllForms();
		void	attendClasses();
		void	notify(Event e) {bell.notify(e);}
};


#endif
