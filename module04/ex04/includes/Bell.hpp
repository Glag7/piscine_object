#ifndef BELL_HPP
# define BELL_HPP

#include <set>

enum class Event
{
	StartPause,
	EndPause
};

class Observer;

class Bell
{
	private:
		std::set<Observer *>	observers;

	public:
		void	notify(Event e) const;
		void	attach(Observer *o);
		void	detach(Observer *o);
};

#endif
