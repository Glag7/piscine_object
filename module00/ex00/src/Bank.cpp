#include <algorithm>
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

const	Bank::Account 	&Bank::createAccount()
{
	Bank::Account	a;

	clients[a.getId()] = a;
	return clients[a.getId()];
}

void	Bank::deleteAccount(Account &a)
{
	clients.erase(a.getId());
}

void	Bank::addMoney(Account &a, int n)
{
	a.money += n * .95;
	money += n * .05;
}

void	Bank::giveLoan(Account &a, int n)
{
	if (money < n)
		throw std::invalid_argument("no money left");
	a.money += n;
	a.loan += n;
	money -= n;
}

void	Bank::payBackLoan(Account &a, int n)
{
	if (a.money < n)
		throw std::invalid_argument("no money left");
	if (a.loan < n)
		throw std::invalid_argument("too much money");
	a.money -= n;
	a.loan -= n;
	money += n;
}

void	Bank::takeMoney(Account &a, int n)
{
	if (a.money < n)
		throw std::invalid_argument("no money left");
	a.money -= n;
	money += n;
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
