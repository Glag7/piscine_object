#ifndef ARTICLE_HPP
# define ARTICLE_HPP

#include <string>

class Article
{
	private:
		std::string	name;
		unsigned	price;

	public:
		Article(const std::string &name, unsigned price);
		bool	operator==(const Article &a) const;
		bool	operator<(const Article &a) const;
		bool	operator>(const Article &a) const;

		const std::string	&getName() const {return name;}
		unsigned			getPrice() const {return price;}
};

#endif
