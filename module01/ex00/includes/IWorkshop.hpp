#ifndef IWORKSHOP_HPP
# define IWORKSHOP_HPP

#include <vector>
#include "Worker.hpp"
#include "Tool.hpp"

class IWorkshop
{
	protected:
		std::vector<Worker *>	workers;

	public:
		virtual ~IWorkshop() {}

		virtual void	addWorker(Worker *w) = 0;
		virtual void	removeWorker(Worker *w) = 0;
		virtual bool	checkWorker(Worker *w) = 0;
		virtual void	executeWorkDay() = 0;
};

#endif
