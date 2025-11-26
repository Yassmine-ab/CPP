#include "Point.hpp"

static Fixed	calculateTriangleArea(Point const& a, Point const& b, Point const& c)
{
	Fixed	area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY()));

	if (area < 0)
		area = area * Fixed(-1);
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	mainArea = calculateTriangleArea(a, b, c);

	if (mainArea == Fixed(0))
		return (false);

	Fixed	area1 = calculateTriangleArea(point, b, c);
	Fixed	area2 = calculateTriangleArea(a, point, c);  
	Fixed	area3 = calculateTriangleArea(a, b, point);

	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
		return (false);
	return (area1 + area2 + area3 == mainArea);
}

/*
Si une des aires calculées est égale à zéro, le point se trouve sur un des côtés du triangle.
Si la somme des trois aires est égale à l'aire principale, le point est à l'intérieur du triangle.
*/