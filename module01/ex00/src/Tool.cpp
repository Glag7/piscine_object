#include "Tool.hpp"
#include "Worker.hpp"

Tool::Tool(const std::string &type, unsigned uses) :
	type(type),
	uses(uses),
	worker(NULL)
{
	std::cout << "Tool constructor.\n";
}

void	Tool::useTool()
{
	if (worker == NULL)
		throw std::runtime_error("tool not owned by worker");
	use();
	if (--uses == 0)
	{
		std::cout << "Tool  broke.\n";
		if (worker)
			worker->removeTool(this);
	}
	else
		std::cout << "Uses remaining: " << uses << ".\n";
}

void	Tool::setWorker(Worker *w)
{
	std::cout << "Setting new tool worker for " << type << ".\n";
	if (worker)
		worker->removeTool(this);
	worker = w;
}

void	Tool::removeWorker()
{
	std::cout << "Removing worker for: " << type << ".\n";
	worker = NULL;
}
