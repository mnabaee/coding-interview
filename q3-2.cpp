
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


struct Node{
	int value;
	int minValue;
	Node* nextNode;
}


class stack{
	Node* top;
void push(int newVal){
	Node* newNode = new Node();
	newNode->value = newVal;
	newNode->minValue = min(newVal, top->minValue);
newNode->nextNode = top;
	top = newNode;
}
void pop(){
	Node* newTop = top->nextNode;
	delete top;
	top = newTop;
}
int top(){
	return top->value;
}
int min(){
	return top->minValue;
}
}



