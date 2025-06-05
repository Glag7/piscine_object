#ifndef DATEHEADER_HPP
# define DATEHEADER_HPP

#include "IHeader.hpp"

class DateHeader : public IHeader
{
	public:
		DateHeader();

		void	outputHeader(std::ostream &o);
};

#endif
