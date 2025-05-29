#include "Worker.hpp"
#include "Tool.hpp"

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
