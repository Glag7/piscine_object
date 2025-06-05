#include "Command.hpp"
#include "Article.hpp"

unsigned	Command::idCount = 0;

Command::Command(const std::string &client) :
	id(idCount++),
	date(std::chrono::high_resolution_clock::now()),
	client(client),
	articles()
{
}

void	Command::addArticle(const Article &a)
{
	++articles[a];
}

void	Command::addArticle(const Article &a, unsigned n)
{
	articles[a] += n;
}

unsigned	Command::get_total_price() const
{
	unsigned	total = 0;

	for (const auto	&entry : articles)
		total += entry.first.getPrice() * entry.second;
	return total;
}
