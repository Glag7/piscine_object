#include <iostream>
#include "Worker.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

int main()
{
	Worker	bob, joe;
	Hammer	ham, hum;
	Shovel	sho;

	std::cout << "\n";
	bob.giveTool(&ham);
	bob.giveTool(&sho);
	std::cout << "bob " << bob;
	try
	{
		bob.giveTool(NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << "error: " << e.what() << "\n";
	}
	std::cout << "\n";
	bob.useTool(&ham);
	try
	{
		bob.useTool(&hum);
	}
	catch (std::exception &e)
	{
		std::cerr << "error: " << e.what() << "\n";
	}
	std::cout << "\n";
	bob.giveTool(&hum);
	joe.giveTool(&ham);
	std::cout << "bob " << bob;
	std::cout << "joe " << joe;
	std::cout << "\n";
	joe.useTool(&ham);
	std::cout << "joe " << joe;
	std::cout << "\n";
	bob.giveTool(&hum);
	std::cout << "bob " << bob;
	bob.giveTool(&hum);
	std::cout << "bob " << bob;
	std::cout << "\n";
	Shovel	*sha = bob.getTool<Shovel>();
	bob.useTool(sha);
	bob.removeTool(sha);
	try
	{
		bob.removeTool(NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << "error: " << e.what() << "\n";
	}
	std::cout << "bob " << bob;
	std::cout << "\n";
	Shovel	*no = bob.getTool<Shovel>();
	std::cout << no << "\n";
}
