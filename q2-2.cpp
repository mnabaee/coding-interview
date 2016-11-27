

#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


struct Node{
	Node* nextNode;
	Val value;
}


void findNthToLast(Node** head, n, Node* result){
	if(head == NULL){
		result = NULL;
		return;
	}
	
	int size = 1;
	Node* currNode = *head;
	while(currNode != NULL){
		currNode = currNode -> nextNode;
		size++;
	}


	if( n >= size ){
		currNode = *head;
		for(int i = 0; i <n; i++){
			currNode = currNode->nextNode;
		}
		result = currNode;
		return;
	}else{
		//Print Error ….
	}
	
	


}

