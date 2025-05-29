#ifndef WORKER_HPP
# define WORKER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Position.hpp"
#include "Statistic.hpp"
#include "IWorkshop.hpp"

class Tool;

class Worker
{
	private:
		Position					pos;
		Statistic					stat;
		std::vector<Tool *>			tools;
		std::vector<IWorkshop *>	workshops;

	public:
		Worker();

		const std::vector<Tool *>	&getTools() const {return tools;}
		const Position				&getPos() const {return pos;}
		const Statistic				&getStat() const {return stat;}

		void		giveTool(Tool *tool);
		void		removeTool(Tool *tool);
		void		useTool(Tool *tool);
		template <class ToolType>
		ToolType	*getTool() const;
		void		joinWorkShop(IWorkshop *ws);
		void		leaveWorkShop(IWorkshop *ws);
		template <class ToolType>
		void		work();
};

std::ostream	&operator<<(std::ostream &o, const Worker &w);

#include "Worker.inl"

#endif
