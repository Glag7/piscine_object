#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

Worker::Worker() :
	pos(),
	stat()
{
	std::cout << "Worker constructor.\n";
}

void	Worker::giveTool(Tool *tool)
{
	if (tool == NULL)
		throw std::runtime_error("null found");
	std::cout << "Giving tool " << tool->getType() << "\n";
	tool->setWorker(this);
	tools.push_back(tool);
}

void	Worker::removeTool(Tool *tool)
{
	if (tool == NULL)
		throw std::runtime_error("null found");
	
	std::vector<Tool *>::iterator 	pos = std::find(tools.begin(), tools.end(), tool);

	if (pos == tools.end())
		throw std::runtime_error("tool not in inventory");
	tools.erase(pos);
	tool->removeWorker();
	std::cout << "Tool removed: " << tool->getType() << "\n";
	for (std::vector<IWorkshop *>::iterator it = workshops.begin(); it < workshops.end(); ++it)
	{
		if ((*it)->checkWorker(this))
			std::cout << "Worker is sad.\n";
	}
}

void	Worker::useTool(Tool *tool)
{
	if (tool == NULL)
		throw std::runtime_error("null found");
	if (std::find(tools.begin(), tools.end(), tool) == tools.end())
		throw std::runtime_error("tool not in inventory");
	std::cout << "Worker using tool.\n";
	tool->useTool();
}

void	Worker::joinWorkShop(IWorkshop *ws)
{
	if (ws == NULL)
		throw std::runtime_error("null found");
	if (std::find(workshops.begin(), workshops.end(), ws) != workshops.end())
		throw std::runtime_error("workshop already joined");
	try
	{
		ws->addWorker(this);
		workshops.push_back(ws);
		std::cout << "Worker joined workshop.\n";
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Worker cannot join: " << e.what() << ".\n";
	}
}

void	Worker::leaveWorkShop(IWorkshop *ws)
{
	if (ws == NULL)
		throw std::runtime_error("null found");

	std::vector<IWorkshop *>::iterator pos = std::find(workshops.begin(), workshops.end(), ws);

	if (pos == workshops.end())
		throw std::runtime_error("workshop not joined");
	workshops.erase(pos);
	ws->removeWorker(this);
	std::cout << "Worker left workshop.\n";
}

std::ostream	&operator<<(std::ostream &o, const Worker &w)
{
	const Position				&pos = w.getPos();
	const Statistic				&stat = w.getStat();
	const std::vector<Tool *>	&v = w.getTools();

	o << "Worker: \n"
		<< "pos: (" << pos.x << ", " << pos.y << ", " << pos.z << "); "
		<< "stat: (exp: " << stat.exp << ", lvl: " << stat.level << ")\n";
	for (std::vector<Tool *>::const_iterator it = v.begin(); it < v.end(); ++it)
		o << "-" << (*it)->getType() << "\n";
	return o;
}
