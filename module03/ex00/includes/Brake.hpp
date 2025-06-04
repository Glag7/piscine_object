#ifndef BRAKE_HPP
# define BRAKE_HPP

class Engine;

class Brake
{
	private:
		Engine			&engine;
		const unsigned	maxForce;

	public:
		Brake(Engine &engine, unsigned maxForce);

		unsigned	getMaxForce() const {return maxForce;}

		void	brake(unsigned force);
};

#endif
