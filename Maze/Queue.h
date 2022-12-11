
#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include "Point.h"

class Queue {

private:
	int head, tail;
	Point *pointsQueue;
	int logicalSize;

	int addOne(int x);

public:
	Queue(int & h, int & w);
	~Queue();
	int getLogicalSize();
	void makeEmpty();
	bool isEmpty();
	Point front();
	void enQueue(Point point);
	Point deQueue();

};

#endif /* Queue_hpp */
