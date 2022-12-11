#include "Queue.h"

//c`tor
Queue::Queue(int &h, int &w)
{

	this->head = 1;
	this->tail = 0;
	this->logicalSize = h * w;
	this->pointsQueue = new Point[logicalSize];
}

//distractor to queue
Queue::~Queue() {

	delete[] this->pointsQueue;
}

//getter to log size
int Queue::getLogicalSize()
{

	return this->logicalSize;
}

//empty the queue 
void Queue::makeEmpty()
{
	head = 1;
	tail = 0;
}

//add one to the location integer by % of log size
int Queue::addOne(int x)
{
	return ((1 + x) % this->getLogicalSize());
}

//return if the queue is empty
bool Queue::isEmpty()
{
	return (addOne(this->tail) == this->head);
}

//get the first value in queue
Point Queue::front()
{

	if (isEmpty())
	{
		cout << "Eror QUEUE EMPTY\n";
		exit(1);
	}
	return (pointsQueue[this->head]);
}

//add value to the queue
void Queue::enQueue(Point point)
{
	if (addOne(addOne(this->tail)) == this->head)
	{
		cout << "Eror QUEUE FULL\n";
		exit(1);
	}
	this->tail = addOne(this->tail);
	pointsQueue[this->tail] = point;

}

//delete the first one in the queue and return his data
Point Queue::deQueue()
{

	if (isEmpty()) {
		cout << "Eror QUEUE EMPTY\n";
		exit(1);
	}
	Point point = pointsQueue[this->head];
	head = addOne(this->head);
	return point;
}
