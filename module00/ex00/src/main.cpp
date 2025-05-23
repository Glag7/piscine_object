#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	Bank	bank(1000);
	
	std::cout << bank;
	bank.createAccount();
	std::cout << bank;
	try
	{
		std::cout << bank[0] << "\n";
		std::cout << bank[999] << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "noooo " << e.what() << "\n";
	}
	bank.createAccount();
	std::cout << bank;
	bank.deleteAccount(bank[1]);
	std::cout << bank;
	bank.addMoney(bank[0], 100);
	std::cout << bank;
	try
	{
		bank.giveLoan(bank[0], 999999);
	}
	catch (std::exception &e)
	{
		std::cout << "noooo " << e.what() << "\n";
	}
	bank.giveLoan(bank[0], 100);
	std::cout << bank;
	try
	{
		bank.payBackLoan(bank[0], 999999);
	}
	catch (std::exception &e)
	{
		std::cout << "noooo " << e.what() << "\n";
	}
	try
	{
		bank.payBackLoan(bank[0], 101);
	}
	catch (std::exception &e)
	{
		std::cout << "noooo " << e.what() << "\n";
	}
	bank.payBackLoan(bank[0], 50);
	std::cout << bank;
	bank.takeMoney(bank[0], 50);
	std::cout << bank;
	return (0);
}
