#ifndef THUESDAYDISCOUNTCOMMAND_HPP
# define THUESDAYDISCOUNTCOMMAND_HPP

#include "Command.hpp"

class ThuesdayDiscountCommand : public Command
{
	public:
		ThuesdayDiscountCommand(const std::string &client);
		
		unsigned	get_total_price() const;
};

#endif
