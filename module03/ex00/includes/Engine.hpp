#ifndef ENGINE_HPP
# define ENGINE_HPP

class Engine
{
	private:
		const unsigned	maxSpeed;
		unsigned		speed;
		bool			running;

	public:
		Engine(double maxSpeed);

		void	accelerate(unsigned speed);
		void	slow_down(unsigned speed);
		void	on();
		void	off();
};

#endif
