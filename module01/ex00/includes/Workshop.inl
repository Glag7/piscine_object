#ifndef WORKSHOP_INL
# define WORKSHOP_INL

template <class ToolType>
Workshop<ToolType>::Workshop()
{
	std::cout << "Workshop constructor.\n";
}

template <class ToolType>
void	Workshop<ToolType>::addWorker(Worker *w)
{
	if (w == NULL)
		throw std::runtime_error("null found");
	if (std::find(workers.begin(), workers.end(), w) != workers.end())
		throw std::invalid_argument("already in workshop");
	if (w->getTool<ToolType>() == nullptr)
		throw std::invalid_argument("missing required tool");
	std::cout << "Added worker.\n";
	workers.push_back(w);
}

template <class ToolType>
bool	Workshop<ToolType>::checkWorker(Worker *w)
{
	if (w == NULL)
		throw std::runtime_error("null found");
	if (std::find(workers.begin(), workers.end(), w) == workers.end())
		throw std::invalid_argument("not in workshop");
	if (w->getTool<ToolType>() == nullptr)
	{
		std::cout << "Worker was kicked.\n";
		removeWorker(w);
		return true;
	}
	return false;
}

template <class ToolType>
void	Workshop<ToolType>::removeWorker(Worker *w)
{
	if (w == NULL)
		throw std::runtime_error("null found");

	std::vector<Worker *>::iterator pos = std::find(workers.begin(), workers.end(), w);
	
	if (pos == workers.end())
		throw std::invalid_argument("not in workshop");
	std::cout << "Worker was removed.\n";
	workers.erase(pos);
}

template <class ToolType>
void	Workshop<ToolType>::executeWorkDay()
{
	std::cout << "Glorious workday.\n";
	for (std::vector<Worker *>::iterator it = workers.begin(); it < workers.end(); ++it)
	{
		std::cout << "Worked is being forced to work.\n";
		(*it)->work<ToolType>();
	}
}

#endif
