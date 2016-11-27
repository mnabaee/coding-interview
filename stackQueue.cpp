
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


struct Node{
	Node* nextNode;
	Val value;
}


class Stack{
	Node* top;
	void push(Val newVal){
		Node* newNode = new Node();
		newNode->value = newVal;
		newNode->nextNode = top;
		Top = newNode;
	}
	Val pop(){
		Val buff = *top;
		Node* newTop = top->nextNode;
		delete top;
		top = newTop;
		return buff;
	}
}


class Queue{
	Node* first;
	Node* last;
	void enqueue(Val newVal){
		Node* newNode = new Node();
		newNode->value = newVal;
		last->nextNode = newNode;
		last = newNode;
	}
	Val dequeue(){
		Val buff = *first;
		Node* newFirst = first->nextNode;
		delete first;
		first = newFirst;
		return buff;
	}
}


