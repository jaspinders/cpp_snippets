#pragma once
#include <string>

using namespace std;
//ListNode.h
class ListNode
{
public:
	int _data;
	ListNode* _next;
};
// --end ListNode.h

class LinkedList
{
private:
	ListNode* head;
	
	int size;
public:
	LinkedList();
	
	int get(int index);
	void addAtHead(int value);
	void addAtTail(int value);
	void addAtIndex(int index,int value);
	void deleteAtIndex(int index);
	string printList();
	virtual ~LinkedList();
};
