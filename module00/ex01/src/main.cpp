#include <iostream>
#include "Graph.hpp"

int main(int argc, char **argv)
{
	try
	{
		Graph	graph(Vector2(10, 10));

		for (int i = 1; i < argc; ++i)
		{
			try
			{
				graph.readFile(argv[i]);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << "\n";
			}
		}
		if (argc == 1)
		{
			try
			{
				graph.readFile("/dev/stdin");
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << "\n";
			}
		}
		graph.outputConsole();
		//graph.outputImage();
	}
	catch (std::exception &e)
	{
		std::cerr << "fat ass catch: " << e.what() << "\n";
	}
}
