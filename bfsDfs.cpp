
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


class Graph{
	int numNodes;
	list<int> * adjNodes;
	Graph(int nodes){
		numNodes = nodes;
		adjNodes = new list<int>[nodes];
	}
	void addEdge(node i, node j){
		adjNodes[i].push_back(j);
		adjNodes[j].push_back(j);
	}
	void runDFS(int start){
	bool* visited = new bool[numNodes];
	for(unsigned int i = 0; i < numNodes; i++){
		visited[i] = true;
	}
	stack nodes;
	stack.push(start);
	while( !stack.empty() ){
		int currNode = stack.top();
		stack.pop();
		for(list<int>::iterator it = adjNodes[currNode].begin(); it != adjNodes[currNode].end(); it++){
			if( !visited[*it] ){
				visited[*it] = true;
				stack.push(*it);
				break;
			}
		}
		
	}


	


	}


	void runBFS(int start){
		bool* visited = new bool[numNodes];
		for(unsigned int i = 0; i < numNodes; i++)
			visited[i] = true;
		queue<int> nodes;
		nodes.push_back(start);
		while( !nodes.empty() ){
			int currNode = nodes.front();
			nodes.pop_front();
			for(list<int>::iterator it = adjNodes[currNode].begin(); it != adjNodes[currNode].end(); it++){
				if( !visisted[*it] ){
					visited[*it] = true;
					nodes.push_back(*it);
				}
			}
		}


	}




}

