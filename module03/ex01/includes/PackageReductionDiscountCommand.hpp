#ifndef PACKAGEREDUCTIONCOMMAND_HPP
# define PACKAGEREDUCTIONCOMMAND_HPP

#include "Command.hpp"

class PackageReductionDiscountCommand : public Command
{
	public:
		PackageReductionDiscountCommand(const std::string &client);
		
		unsigned	get_total_price() const;
};

#endif
