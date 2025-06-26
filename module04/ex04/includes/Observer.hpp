#ifndef OBSERVER_HPP
# define OBSERVER_HPP

#include "Bell.hpp"

class Observer
{
	private:
		Bell	&b;

	public:
		Observer(Bell &b);
		virtual ~Observer();

		virtual void	receive(Event e) = 0;
};

#endif
