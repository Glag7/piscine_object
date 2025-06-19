#ifndef SINGLETON_HPP
# define SINGLETON_HPP

#include <set>

template <class T>
class Singleton
{
	private:
		Singleton<T>() {}

	public:
		Singleton<T>(const Singleton<T> &) = delete;

		void	operator=(const Singleton<T> &) = delete;

		static T	&getInstance()
		{
			static T	singleton;

			return singleton;
		}
};

template <class T>	
using SSet = Singleton<std::set<T>>;

#endif
