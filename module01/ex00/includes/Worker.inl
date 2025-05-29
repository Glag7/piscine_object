#ifndef WORKER_INL
# define WORKER_INL

#include "nullptr.hpp"

template <class ToolType>
ToolType	*Worker::getTool() const
{
	for (std::vector<Tool *>::const_iterator it = tools.begin(); it < tools.end(); ++it)
	{
		ToolType	*tool = dynamic_cast<ToolType *>(*it);
		
		if (tool != NULL)
			return tool;
	}
	return nullptr;
}

template <class ToolType>
void	Worker::work()
{
	std::cout << "Worker is working\n";
	useTool(getTool<ToolType>());
}

#endif
