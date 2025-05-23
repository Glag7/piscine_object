#include "Graph.hpp"

Graph::Graph(const Vector2 &size) : size(size)
{
}

void	Graph::addPoint(const Vector2 &point)
{
	if (point.x < 0.f || point.x > size.x || point.y < 0.f || point.y > size.y)
		throw (std::invalid_argument("point out of bounds"));
	points.insert(point);
}
