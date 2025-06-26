#include "Observer.hpp"
#include "Bell.hpp"

Observer::Observer(Bell &b) : b(b)
{
	b.attach(this);
}

Observer::~Observer()
{
	b.detach(this);
}
