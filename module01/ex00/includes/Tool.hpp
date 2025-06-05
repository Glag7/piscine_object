#ifndef TOOL_HPP
# define TOOL_HPP

#include <string>

class Worker;

class Tool
{
	private:
		std::string	type;
		unsigned	uses;
		Worker		*worker;
		virtual void	use() = 0;

	public:
		Tool(const std::string &type, unsigned uses);
		virtual ~Tool() {}

		const std::string	&getType() const {return type;}

		void	useTool();
		void	setWorker(Worker *worker);
		void	removeWorker();
};

#endif
