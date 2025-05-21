#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() :
	money(0)
{
}

Bank::Bank(int money) :
	money(money)
{
}

const Bank::Account 	&Bank::createAccount()
{
	Bank::Account	a;

	clients[a.getId()] = a;
	return clients[a.getId()];
}

std::ostream&	operator<<(std::ostream& os, const Bank& bank)
{
	os << "Bank infos\n"
		<< "Money: " << bank.getMoney() << "\n"
		<< "Clients: \n";
	for (std::map<int, Bank::Account>::const_iterator it = bank.getClients().begin();
		it != bank.getClients().end(); ++it)
		os << " " << it->second << std::endl;
	return (os);
}
