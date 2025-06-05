#ifndef STRINGHEADER_HPP
# define STRINGHEADER_HPP

#include <string>
#include <IHeader.hpp>

class StringHeader : public IHeader
{
	private:
		std::string	s;

	public:
		StringHeader(const std::string &s);

		void	outputHeader(std::ostream &o);
};

#endif
