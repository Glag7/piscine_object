#include <ctime>
#include "ThuesdayDiscountCommand.hpp"
#include "Article.hpp"

ThuesdayDiscountCommand::ThuesdayDiscountCommand(const std::string &client) : Command(client)
{
}

unsigned	ThuesdayDiscountCommand::get_total_price() const
{
	unsigned	total = Command::get_total_price();
	auto		tmp = std::chrono::system_clock::to_time_t(date);

	if (std::localtime(&tmp)->tm_wday == 2)
		return total * .9;
	return total;
}
