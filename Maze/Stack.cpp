#include "Stack.h"

Stack::Stack()
{
	this->head = nullptr;
}

Stack::~Stack()
{
	this->makeEmpty();
}

void Stack::makeEmpty()
{
	ListNode *temp;
	while (this->head != nullptr)
	{
		temp = this->head;
		this->head = this->head->getNext();
		delete temp;
	}
	this->head = nullptr;
}

bool Stack::isEmpty()
{
	return (this->head == nullptr);
}

void Stack::push(const Point & p)
{
	ListNode * newNode = new ListNode(p, this->head);
	/*if(!newNode){
		cout << "Alloction Eror\n";
		exit(2);
	}*/
	this->head = newNode;
}

Point Stack::pop()
{
	if (!isEmpty())
	{
		Point tempP = this->head->getPoint();	//the data of the node we want to delte
		ListNode *toDelte = this->head;	//the node we want to delete
		this->head = this->head->getNext();
		delete toDelte;
		return tempP;
	}
	else
	{
		cout << "The stack is empty\n";
		exit(0);
	}

}

Point Stack::top()
{
	if (!isEmpty())
		return this->head->getPoint();
	cout << "The stack is empty\n";
	exit(0);


}

