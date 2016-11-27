
#include <stdio.h>
#include <stdlib.h>
#include <map>


using namespace std;


class MyQueue{
	Stack* readStack;
	Stack* writeStack;
	MyQueue(){
		readStack = new Stack();
		writeStack = new Stack();
	}
	~MyQueue(){
		delete readStack;
		delete writeStack;
	}
	void enqueue(Val newVal){
		writeStack->push(newVal);
	}
	Val dequeue(){
		if(readStack->empty()){
			while( !writeStack->empty() ){
				readStack->push(writeStack->top());
				writeStack->pop();
			}
		}
		if(readStack->empty()){
			//error
			return ...
		}else{
			Val buff = readStack->top();
			readStack->pop();
			return buff;
		}


	}


}


