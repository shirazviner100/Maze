#include "Point.h"

Point::Point(int x, int y) : x(x), y(y)
{
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}


void Point::print() const
{
	cout << "The point: (" << this->x << ", " << this->y << ")\n";
}
