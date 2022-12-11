#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <string.h>
using namespace std;
#include "ListNode.h"

class Stack {
private:
	ListNode *head;	//pointer to stack top

public:
	Stack();
	~Stack();

	void makeEmpty();
	bool isEmpty();
	void push(const Point & p);
	Point pop();
	Point top();


};



#endif // !__STACK_H
