#ifndef HAMMER_HPP
# define HAMMER_HPP

#include <iostream>
#include "Tool.hpp"

class Hammer : public Tool
{
	private:
		void	use();

	public:
		Hammer();
};

#endif
