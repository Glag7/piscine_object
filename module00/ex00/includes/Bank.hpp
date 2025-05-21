#ifndef BANK_HPP
# define BANK_HPP

#include <iostream>
#include <map>

struct Bank
{
		struct Account;

	private:
		int						money;
		std::map<int, Account>	clients;

	public:
		Bank();
		Bank(int money);

		const int						&getMoney() const {return money;}
		const std::map<int, Account>	&getClients() const {return clients;}
		const Account					&operator[](int id) const {return clients.at(id);}
		Account							&operator[](int id) {return clients.at(id);}

		const Account 	&createAccount();
		void			deleteAccount(Account &a);
		void			addMoney(Account &a, int n);
		void			giveLoan(Account &a, int n);
		void			payBackLoan(Account &a, int n);
		void			takeMoney(Account &a, int n);
};

std::ostream&	operator<<(std::ostream& os, const Bank& bank);

#endif
