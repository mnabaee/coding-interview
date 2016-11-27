
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


class Rods{
Stack<int>* stacks;	


	Rods(){
		stacks = new Stack<int>[3];
	}
	void moveDisk(int from, int to){
		int valFrom = stacks[i]->top();
		int valTo = stacks[j]->top();
		if(valFrom < valTo){
			stacks[i]->pop();
			stacks[j]->push(valTo);
		}
	}
	


}


