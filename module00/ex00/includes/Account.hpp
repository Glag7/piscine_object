#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#include <iostream>
#include <vector>
#include "Bank.hpp"

struct	Bank::Account
{
		static int	nextId;

		friend	struct Bank;
	
	private:
		int	id;
		int	money;
		int	loan;

	public:
		Account();
		Account(const Account &a);

		const int	&getId() const {return id;}
		const int	&getMoney() const {return money;}
		const int	&getLoan() const {return loan;}
};

std::ostream&	operator<<(std::ostream& os, const Bank::Account& account);

#endif
