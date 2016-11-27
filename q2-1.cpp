
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


struct Node{
	Node* nextNode;
	Val value;
}


void removeDuplicates(Node** head){
	if(head == NULL){
		return;
	}
	map<int, bool> nodesMap;
	nodesMap[(*head)->value] =  true;
	Node* currNode = *head;
	while(currNode->nextNode != NULL){
		if( nodesMap.find(currNode->nextNode->value) == nodesMap.end()  ){
			nodesMap[currNode->nextNode->value] = true;
			currNode = currNode->nextNode;
		}else{
			currNode->nextNode = currNode->nextNode->nextNode;
		}
	}
}


Void removeDuplicatesNoBuffer(Node** head){
	if(head == NULL){
		return;
	}


	Node* currNode = *head;
	Node* checkerNode = *head;




	while(currNode->nextNode != NULL){
		checkerNode = currNode;
		while(checkerNode->nextNode != NULL){
			if(currNode->value == checkerNode->nextNode->value){
				checkerNode->nextNode = checkerNode->nextNode->nextNode;
			}else{
				checkerNode = checkerNode->nextNode;
			}
		}
		currNode = currNode->nextNode;
	}


}

