#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Point	a(0.0f, 0.0f);			// Vertex A
	Point	b(10.0f, 0.0f);			// Vertex B
	Point	c(5.0f, 10.0f);			// Vertex C
	Point	inside(5.0f, 3.0f);		// Point inside triangle
	Point	outside(15.0f, 5.0f);	// Point outside triangle
	Point	onVertex(0.0f, 0.0f);	// Point on vertex A
	Point	onEdgeAb(5.0f, 0.0f);	// Point on edge AB
	Point	onEdgeAc(2.5f, 5.0f);	// Point on edge AC

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A(" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B(" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << std::endl;	
	std::cout << "Test Results:" << std::endl;
	std::cout << "Point(" << inside.getX() << ", " << inside.getY() << ") ";
	std::cout << "is " << (bsp(a, b, c, inside) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << "Point(" << outside.getX() << ", " << outside.getY() << ") ";
	std::cout << "is " << (bsp(a, b, c, outside) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << "Point(" << onVertex.getX() << ", " << onVertex.getY() << ") ";
	std::cout << "is " << (bsp(a, b, c, onVertex) ? "INSIDE" : "OUTSIDE") << " the triangle (on vertex A)" << std::endl;
	std::cout << "Point(" << onEdgeAb.getX() << ", " << onEdgeAb.getY() << ") ";
	std::cout << "is " << (bsp(a, b, c, onEdgeAb) ? "INSIDE" : "OUTSIDE") << " the triangle (on edge AB)" << std::endl;
	std::cout << "Point(" << onEdgeAc.getX() << ", " << onEdgeAc.getY() << ") ";
	std::cout << "is " << (bsp(a, b, c, onEdgeAc) ? "INSIDE" : "OUTSIDE") << " the triangle (on edge AC)" << std::endl;
	return (0);
}