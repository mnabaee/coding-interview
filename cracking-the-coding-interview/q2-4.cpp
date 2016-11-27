
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


struct Node{
	Node* nextNode;
	Val value;
}


void sumTwoLinkList(Node** first, Node** second, Node* result){


Node* currResult = new Node();
result = currResult;
Node* currFirst = *first;
Node* currSecond = *second;
int carry = 0;
while(currFirst != NULL){
	currResult->value = (currFirst->value + currSecond->value + carry ) % 10;
	carry = (currFirst->value + currSecond->value + carry ) / 10;
	currResult->nextNode = new Node();
	currResult = currResult->nextNode;
	currFirst = currFirst->nextNode;
	currSecond = currSecond->nextNode;
}	


}


