#include "StringHeader.hpp"

StringHeader::StringHeader(const std::string &s) : s(s)
{
}

void	StringHeader::outputHeader(std::ostream &o)
{
	o << s;
}
