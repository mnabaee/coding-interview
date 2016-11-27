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


void insertToBST(TreeNode* root, int value){
	if(root->value <= value){
		//add to the right 
		if(root->rChild == NULL){
			TreeNode* newNode = new TreeNode();
			newNode->value = value;
			newNode->parent = root;
			root->rChild = newNode;
		}else{
			insertToBST(root->rChild, value);
		}
	}else{
		//add to the left
		if(root->lChild == NULL){
			TreeNode* newNode = new TreeNode();
			newNode->value = value;
			newNode->parent = root;
			root->lChild = newNode;
		}else{
			while(root->parent != NULL && root->parent->lChild == root ){
				root = root->parent;
			}
			return root;
		}


	}
}








TreeNode* findSuccessor(TreeNode* curr){
if(curr->parent == NULL){
	return leftMostNode(curr->rChild);
}
if(curr->rChild){
	return leftMostNode(curr->rChild);
}
if(curr->parent->lChild == curr){
	return curr->parent;
}else{
	return findSuccessor(curr->parent);
}




}


TreeNode* leftMostNode(TreeNode* root){
if(root == NULL) return NULL;
	while(root->lChild){
		root = root->lChild;
	}
	return root;
}

