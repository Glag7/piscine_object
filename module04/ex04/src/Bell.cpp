#include <iostream>
#include "Bell.hpp"
#include "Observer.hpp"

void	Bell::notify(Event e) const
{
	std::cout << "Bell ringing\n";
	for (Observer *o : observers)
		o->receive(e);
}

void	Bell::attach(Observer *o)
{
	observers.insert(o);
}

void	Bell::detach(Observer *o)
{
	if (observers.find(o) != observers.end())
		observers.erase(observers.find(o));
}
