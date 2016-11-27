
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


struct TreeNode{
	TreeNode* lChild;
	TreeNode* rChild;
	TreeNode* parent;
	int value;
}


int getMaxDepth(TreeNode* root){
	if(root == NULL) return 0;
	return max(getMaxDepth(root->lChild), getMaxDepth(root->rChild) ) + 1;
}


void markNode(TreeNode* root, int rootDepth, list<TreeNode*> results){
	if(root == NULL) return;
	results[rootDepth].push_back(root);
	markNode(root->lChild, rootDepth+1, results);
	markNode(root->rChild, rootDepth+1, results);
}


void createLists(TreeNode* root, list<TreeNode*> * results){
	results = new list<TreeNode*>[getMaxDepth(root)];
	markNode(root, 0, results);
}
