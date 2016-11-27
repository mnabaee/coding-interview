
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


struct StackNode{
	Stack stack;
	int size;
	StackNode* next;
	StackNode* prev;
}


Class SetOfStacks{
int maxStackSize;
StackNode* topStack;
StackNode* firstStack;
	SetOfStacks(int maxStackSize_){
		maxStackSize = maxStackSize_;
		topStack = new Stack(maxStackSize);
		firstStack = topStack;
		topStack->size = 0;
}
	
	void push(Value newVal){
		if(topStackSize == maxStackSize){
StackNode* newSN = new StackNode();
newSN->prev = top;
if(topStack == NULL){
	firstStack = newSN;
}
topStack = newSN;
		}
		topStack->stack.push(newVal);
		topStack->size++;
	}
	void pop(){
		if(topStack == NULL){
			//print error!
			return;
		}
		topStack->stack.pop();
		topStack->size--;
		if(topStack->size == 0){
			StackNode* newTop = topStack->next;
			delete topStack;
			top = newTop;
		}
	}
	Value top(){
	return topStack->stack.top();
	}


	void popAt(int stackIdx){
		int cnt = 0;
		StackNode* currStack = firstStack;
		while(cnt < stackIdx){
			currStack = currStack->prev;
			if(currStack == NULL){
				//print error
				return;
			}
		}
		currStack->stack.pop();
		currStack->size --;
		if(currStack->size == 0){
			//remove it!
			if(currStack->next != NULL){
				currStack->next->prev = currStack->prev;
			}
			if(currStack->prev != NULL){
				currStack->prev->prev = currStack->next;
			}
			delete currStack;
		}
		
		
	}




}

