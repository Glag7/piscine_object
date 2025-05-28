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
		Tool(const std::string &type);

		void			useTool();
		void			setWorker(Worker *worker);
};
