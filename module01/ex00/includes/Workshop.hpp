#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>
#include "nullptr.hpp"
#include "Worker.hpp"
#include "Tool.hpp"
#include "IWorkshop.hpp"

template <class ToolType>
class Workshop : public IWorkshop
{
	public:
		Workshop();

		void	addWorker(Worker *w);
		void	removeWorker(Worker *w);
		bool	checkWorker(Worker *w);
		void	executeWorkDay();
};

#include "Workshop.inl"

#endif
