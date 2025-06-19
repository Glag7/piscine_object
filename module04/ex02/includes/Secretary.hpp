#ifndef SECRETARY_HPP
# define SECRETARY_HPP

#include "Person.hpp" 
#include "Form.hpp"

class Secretary : public Person
{
	private:

	public:
		Secretary();

		Form*	createForm(FormType formType);
};


#endif
