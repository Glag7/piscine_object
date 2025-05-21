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
	return (0);
}
