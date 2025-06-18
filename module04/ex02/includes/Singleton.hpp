#ifndef SINGLETON_HPP
# define SINGLETON_HPP

#include <vector>

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
using SVector = Singleton<std::vector<T>>;

#endif
