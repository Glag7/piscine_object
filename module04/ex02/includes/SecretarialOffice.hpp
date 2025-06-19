#ifndef SECRETARIALOFFICE_HPP
# define SECRETARIALOFFICE_HPP

#include <set>
#include "Room.hpp"

class Form;

class SecretarialOffice: public Room
{
	private:
		std::set<Form *>	archivedForms;

	public:
		SecretarialOffice();
		~SecretarialOffice();

		bool	canEnter(Person* p);
		void	addForm(Form *f);
};

#endif
