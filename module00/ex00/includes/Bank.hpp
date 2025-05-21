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

		void			addMoney(Account &a);
		const Account 	&createAccount();
		void			deleteAccount();
		void			giveLoan(Account &a, int loan);
		void			payBackLoan(Account &a, int money);
		void			takeMoney(Account &a, int money);
};

std::ostream&	operator<<(std::ostream& os, const Bank& bank);

#endif
