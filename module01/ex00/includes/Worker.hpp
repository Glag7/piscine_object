#include <iostream>
#include <vector>
#include "Position.hpp"
#include "Statistic.hpp"

class Tool;

class Worker
{
	private:
		Position			pos;
		Statistic			stat;
		std::vector<Tool *>	tools;

	public:
		Worker();

		void	giveTool(Tool *tool);
		void	removeTool(Tool *tool);
		//use tool
//		Tool	*GetTool<ToolType>()
};
