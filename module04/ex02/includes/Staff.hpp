#ifndef STAFF_HPP
# define STAFF_HPP

#include "Person.hpp"

class Form;

class Staff : public Person
{
	private:

	public:
		Staff(const std::string &name) : Person(name) {}

		void	sign(Form* form);
};

#endif
