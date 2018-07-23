#include "stdafx.h"
#include "LinkedList.h"
#include <string>


using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
	size = 0;
}


LinkedList::~LinkedList()
{
	ListNode* tmp = head;
	ListNode* pre;
	while (tmp->_next != nullptr)
	{
		pre = tmp;
		tmp = tmp->_next;
		delete pre;
	}
	delete tmp;
}

void LinkedList::addAtHead(int value)
{
	ListNode* newNode = new ListNode();
	newNode->_data = value;
	this->head = newNode;
	++size;
}

void LinkedList::addAtTail(int value)
{
	ListNode* tail = this->head;
	ListNode* newNode = new ListNode();
	newNode->_data = value;
	newNode->_next = NULL;

	while (tail->_next != nullptr)
		tail = tail->_next;

	tail->_next = newNode;
	++size;
}

int LinkedList::get(int index)
{
	int iter = 0;
	int retVal = -1;
	ListNode* temp = head;
	if (index == 0)
		retVal = head->_data;

	while ((temp->_next != nullptr) && iter < index)
	{
		temp = temp->_next;
		++iter;
	}
	
	if (iter == index) //index is valid
		retVal = temp->_data;
	else
		retVal = -1;
	
	return retVal;
}

void LinkedList::addAtIndex(int index, int value)
{
	ListNode* tmp = this->head;
	ListNode *newNode = new ListNode();
	newNode->_data = value;

	int iter = 0;
	while (iter < index-1)
	{
		tmp = tmp->_next;
		++iter;
	}
	
	newNode->_next = tmp->_next;
	tmp->_next = newNode;
	++size;
}
void LinkedList::deleteAtIndex(int index)
{
	ListNode* temp = this->head;
	ListNode* nodeToDelete;
	int iter = 0;
	while ((temp->_next != nullptr) && iter < index-1)
		temp = temp->_next;

	//temp points to previous index after the loop
	nodeToDelete = temp->_next;
	temp->_next = nodeToDelete->_next;
	delete nodeToDelete;
}

string LinkedList::printList()
{
	ListNode* tmp = head;
	string ListAsString;
	while (tmp->_next != nullptr)
	{
		ListAsString.append(std::to_string(tmp->_data)).append("->");
		tmp = tmp->_next;
	}
	ListAsString.append(std::to_string(tmp->_data));
	return ListAsString;
}