#ifndef TRANSMISSION_HPP
# define TRANSMISSION_HPP

class Transmission
{
	private:
		const unsigned	nGears;
		int				currentGear;

	public:
		Transmission(unsigned n);

		int	getCurrentGear() const {return currentGear;}

		void	up();
		void	down();
		void	reverse();
};

#endif
