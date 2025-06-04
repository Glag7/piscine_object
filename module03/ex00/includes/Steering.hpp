#ifndef STEERING_HPP
# define STEERING_HPP

class Steering
{
	private:
		const unsigned	maxAngle;
		int				angle;

	public:
		Steering(unsigned maxAngle);

		int	getMaxAngle() const {return static_cast<int>(maxAngle);}
		int	getAngle() const {return angle;}

		void	straighten();
		void	turn(int angle);
};

#endif
