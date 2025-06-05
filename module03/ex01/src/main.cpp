#include <iostream>
#include "Command.hpp"
#include "Article.hpp"
#include "ThuesdayDiscountCommand.hpp"
#include "PackageReductionDiscountCommand.hpp"

int main()
{
	Command	c("bob");

	c.addArticle(Article("wow", 3));
	c.addArticle(Article("wow", 3));
	c.addArticle(Article("wow4", 3), 4);
	std::cout << "command 1 "<< c.get_total_price() << "\n";
	
	ThuesdayDiscountCommand	t("bob");
	Command					*cptr = &t;

	t.addArticle(Article("wow4", 3), 4);
	std::cout << "command 2 "<< t.get_total_price() << "\n";
	std::cout << "command 2 "<< cptr->get_total_price() << "\n";

	PackageReductionDiscountCommand	b("bob");
	Command							*cptr2 = &b;
	
	b.addArticle(Article("huh", 160));
	std::cout << "command 3 "<< b.get_total_price() << "\n";
	std::cout << "command 3 "<< cptr2->get_total_price() << "\n";

}
