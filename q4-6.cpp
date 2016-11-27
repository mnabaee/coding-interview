#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


struct TreeNode{
	TreeNode* lChild, rChild, parent;
	int key;
}


TreeNode* findAncestor(TreeNode* i, TreeNode* j){
	TreeNode* iParent = i;
	while(iParent != NULL){
		iParent = iParent->parent;
	TreeNode* jParent = j;
		while(jParent != NULL){
			if(iParent == jParent){
				return iParent;
			}
			jParent = jParent->parent;
		}
	}
	return NULL;
}


TreeNode* findAncestor2(TreeNode* i, TreeNode* j){
	map<TreeNode*, bool) visitedNodes;
	while(i){
		visitedNodes[i] = true;
		i = i->parent;
	}
	while(j && !visitedNodes[j]){
	j = j->parent;
	}
	return j;
}
