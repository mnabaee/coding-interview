#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


struct TreeNode{
	TreeNode* lChild;
	TreeNode* rChild;
	value;
}


void createBT(int* array, int size, TreeNode* root){
	root = new TreeNode;
	root->value = array[ size/2 ];
	createBT(array, size/2 - 1, root->lChild);
	createBT(array + size/2+1, size - size/2);
}
