


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
		adjNodes = new list<int>[numNodes];
	}
	void addEdge(int i, int j){
		adjNodes[i].push_back(j);
		adjNodes[j].push_back(j);
	}
	bool hasRoute(int s, int d){
		bool* visited = new bool[numNodes];
		for(unsigned int i = 0; i < numNodes; i++){
			visisted[i] = false;
		}	
		stack<int> nodes;
		nodes.push(s);
		while(!nodes.empty()){
			int curr = nodes.top();
			nodes.pop();
			for(list<int>::iterator it = adjNodes[curr].begin(); it != adjNodes[curr].end(); it++){
				if(!visited[*it]){
					visited[*it] = true;
					nodes.push(*it);
					if(*it == d){
						return true;
					}
				}
			}
		}
		return false;
	}


}


