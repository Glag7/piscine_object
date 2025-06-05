#ifndef IHEADER_HPP
# define IHEADER_HPP

#include <ostream>

class IHeader
{
	public:
		virtual ~IHeader() {}
		
		virtual void	outputHeader(std::ostream &o) = 0;
};

#endif
