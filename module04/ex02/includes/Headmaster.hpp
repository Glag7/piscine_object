#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

#include <vector>
#include "Staff.hpp"

class Form;

class Headmaster : public Staff
{
	private:
		std::vector<Form*>	_formToValidate;
		
	public:
		void receiveForm(Form* form);
};


#endif
