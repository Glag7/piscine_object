#include "Graph.hpp"

Graph::Graph(const Vector2 &size) : size(size)
{
	if (size.x <= 0 || size.y <= 0)
		throw std::invalid_argument("dumbass");
}

void	Graph::addPoint(const Vector2 &point)
{
	if (point.x < 0.f || point.x > size.x || point.y < 0.f || point.y > size.y)
		throw (std::invalid_argument("point out of bounds"));
	points.insert(point);
}

void	Graph::addLine(const Vector2 &start, const Vector2 &end)
{
	if (start.x < 0.f || start.x > size.x || start.y < 0.f || start.y > size.y
		|| end.x < 0.f || end.x > size.x || end.y < 0.f || end.y > size.y)
		throw (std::invalid_argument("point out of bounds"));

	Vector2	delta = start - end;
	float	steps = std::abs(delta.x) > std::abs(delta.y) ? std::abs(delta.x) : std::abs(delta.y);
	Vector2	inc = Vector2(delta.x / steps, delta.y / steps);
	Vector2	pos = start;
	
	for (float i = 0.f; i < steps; ++i)
	{
		addPoint(pos);
		pos = pos + inc;
	}
}

void	Graph::readFile(const std::string &name)
{
	std::ifstream	file(name.c_str());
	std::string		line;

	if (!file)
		throw	std::invalid_argument(name + ": can't open file");
	while (getline(file, line))
	{
		const char	*line_char = line.c_str();
		char	*end;
		float	x = std::strtol(line_char, &end, 10);
		Vector2	start;
		Vector2	endpt;

		while (std::isspace(*end))
			++end;
		if (*end++ != '/')
		{
			std::cerr << name + ": invalid line\n";
			continue;
		}
		start = Vector2(x, std::strtol(end, &end, 10));
		while (std::isspace(*end))
			++end;
		if (*end == 0)
		{
			addPoint(start);
			continue;
		}
		else if (*end++ != '-')
		{
			std::cerr << name + ": invalid line\n";
			continue;
		}
		x = std::strtol(end, &end, 10);
		while (std::isspace(*end))
			++end;
		if (*end++ != '/')
		{
			std::cerr << name + ": invalid line\n";
			continue;
		}
		endpt = Vector2(x, std::strtol(end, &end, 10));
		while (std::isspace(*end))
			++end;
		if (*end == 0)
			addLine(start, endpt);
		else
			std::cerr << name + ": invalid line\n";
	}
}

void	Graph::outputConsole()
{
	std::set<Vector2>::iterator	it = points.begin();
	Vector2						pos;
	std::string					line;

	for (int i = 0; i < size.x; ++i)
		std::cout << " " << i + 1;
	std::cout << "\n";
	while (1)
	{
		while (it != points.end() && pos < *it)
		{
			++pos.x;
			line += ".";
			if (pos.x >= size.x)
			{
				std::cout << pos.y + 1 << " " + line << "\n";
				line = "";
				pos.x = 0;
				++pos.y;
				if (it != points.end())
					++it;
				if (pos.y >= size.y)
					return;
			}
		}
		line += "X";
	}
}
