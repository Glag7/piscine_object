#include "Article.hpp"

Article::Article(const std::string &name, unsigned price) :
	name(name),
	price(price)
{
}

bool	Article::operator==(const Article &a) const
{
	return name == a.name;
}

bool	Article::operator>(const Article &a) const
{
	return name > a.name;
}

bool	Article::operator<(const Article &a) const
{
	return name < a.name;
}

