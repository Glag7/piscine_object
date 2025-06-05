#include <ctime>
#include "DateHeader.hpp"

DateHeader::DateHeader()
{
}

void	DateHeader::outputHeader(std::ostream &o)
{
	std::time_t	now = std::time(nullptr);
	std::tm		utc_tm;

	gmtime_r(&now, &utc_tm);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y/%m/%d:%H:%M:%S", &utc_tm);
	o << buffer << ": ";
}
