#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

#include <set>
#include "Staff.hpp"

class Form;

class Headmaster : public Staff
{
	private:
		std::set<Form *>	formsToSign;
		
	public:
		void	receiveForm(Form* form);
		void	signForm(Form *form);
		void	signAllForms();
};


#endif
