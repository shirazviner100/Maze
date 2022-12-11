#ifndef __LISTNODE_H
#define __LISTNODE_H

#include <iostream>
#include <string.h>
using namespace std;
#include "Point.h"

class ListNode
{
private:
	Point p;
	ListNode *next;

public:
	ListNode(const Point & p, ListNode *next);

	void setPoint(Point & point);

	ListNode* getNext() const { return this->next; }
	Point getPoint() const { return this->p; }

	void setNext(ListNode * next);
};


#endif // !__LISTNODE_H
