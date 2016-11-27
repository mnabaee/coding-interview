
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


int getMaxDepth(Node* root){
	if(root == NULL){
		return 0;
	}
	int leftMaxDepth = getMaxDepth(root->leftChild);
	int rightMaxDepth = getMaxDepth(root->rightChild);
	return max(leftMaxDepth, rightMaxDepth) + 1;
}


int getMinDepth(Node* root){
	if(root == NULL){
		return 0;
	}
	int leftMinDepth = getMinDepth(root->leftChild);
	int rightMinDepth = getMinDepth(root->rightChild);
	return min(leftMinDepth, rightMinDepth) + 1;
}


bool checkBalance(Tree* tree){
return (tree->maxDepth() - tree->minDepth()) <= 1;
}


