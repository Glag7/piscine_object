#ifndef SECRETARY_HPP
# define SECRETARY_HPP

#include "Staff.hpp" 
#include "Form.hpp"

class Secretary : public Staff
{
	private:

	public:
		Form*	createForm(FormType formType);
		void	archiveForm();
};


#endif
