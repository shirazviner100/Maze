#include "ListNode.h"


ListNode::ListNode(const Point & p, ListNode *next)
{
	this->p = p;
	this->next = next;
}

void ListNode::setPoint(Point & point)
{
	this->p = point;
}

void ListNode::setNext(ListNode * next)
{
	this->next = next;
}
