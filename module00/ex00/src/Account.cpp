#include "Account.hpp"

int	Bank::Account::nextId = 0;

Bank::Account::Account() :
	id(Bank::Account::nextId++),
	money(0),
	loan(0)
{
}

Bank::Account::Account(const Bank::Account &a) :
	id(a.id),
	money(a.money),
	loan(a.loan)
{
}

std::ostream&	operator<<(std::ostream& os, const Bank::Account& account)
{
	os << "[" << account.getId() << "] - ["
		<< account.getMoney() << "] (-"
		<< account.getLoan() << ")";
	return (os);
}
