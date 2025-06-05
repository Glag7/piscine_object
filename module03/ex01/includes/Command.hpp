#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <chrono>
#include <map>
#include <string>

class Article;

class Command
{
	protected:
		static unsigned	idCount;

		unsigned										id;
		std::chrono::high_resolution_clock::time_point	date;
		std::string										client;
		std::map<Article, unsigned>				articles;

	public:
		Command(const std::string &client);

		void				addArticle(const Article &a);
		void				addArticle(const Article &a, unsigned n);
		virtual unsigned	get_total_price() const;
};

#endif
