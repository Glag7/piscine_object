#include "PackageReductionDiscountCommand.hpp"
#include "Article.hpp"

PackageReductionDiscountCommand::PackageReductionDiscountCommand(const std::string &client) : Command(client)
{
}

unsigned	PackageReductionDiscountCommand::get_total_price() const
{
	unsigned	total = Command::get_total_price();

	if (total > 150)
		return total - 10;
	return total;
}
