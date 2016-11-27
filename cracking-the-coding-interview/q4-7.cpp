#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


struct TreeNode{
	TreeNode* lChild, rChild, parent;
	int key;
}


bool match(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2== NULL) return true;
	else if(root1 == NULL || root2 == NULL) return false;
	else if(root1->key != root2->key) return false;
	else return match(root1->lChild, root2->lChild) && match(root1->rChild, root2->rChild);
}


TreeNode* isSubTree(TreeNode* T1, TreeNode* T2){
	if(match(T1, T2)){
		return T1;
	}
	TreeNode* lFind = isSubTree(T1->lChild, T2);
	if(lFind){
		return lFind;
	}
	else return isSubTree(T1->rChild, T2);
}

