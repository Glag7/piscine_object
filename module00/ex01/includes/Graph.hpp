#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <set>
#include <string>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdint.h>
#include "Vector2.hpp"

class	Graph
{
	private:
		Vector2				size;
		std::set<Vector2>	points;

	public:
		Graph(const Vector2 &size);

		void	addPoint(const Vector2 &point);
		void	addLine(const Vector2 &start, const Vector2 &end);
		void	readFile(const std::string &name);
		void	outputConsole();
		void	outputImage();
};

#endif
