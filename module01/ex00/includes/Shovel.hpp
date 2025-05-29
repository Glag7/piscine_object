#ifndef SHOVEL_HPP
# define SHOVEL_HPP

#include <iostream>
#include "Tool.hpp"

class Shovel : public Tool
{
	private:
		void	use();

	public:
		Shovel();
};

#endif
