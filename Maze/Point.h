#ifndef __POINT_H
#define __POINT_H

#include <iostream>
#include <string.h>
using namespace std;

class Point
{
private:
	int x, y;

public:
	Point(int x = 0, int y = 0);

	int getX() const { return this->x; }
	int getY() const { return this->y; }

	void setX(int x);
	void setY(int y);

	void print() const;
};

#endif // !__POINT_H
