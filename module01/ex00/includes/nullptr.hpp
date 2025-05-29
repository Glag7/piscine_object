#ifndef NULLPTR_HPP
# define NULLPTR_HPP

const
class nullptr_t
{
	public:
		template<class T>
		operator T*() const {return 0;}//return 0 if dereferenced as pointer
		
		template<class C, class T>
		operator T C::*() const {return 0;}//return 0 if dereferenced as member pointer

	private:
		void	operator&() const;//no address

}
nullptr = {};

#endif
