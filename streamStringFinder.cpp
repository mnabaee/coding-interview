#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int charToInt(char c){
	return ((int) c )- 87 - 10;
};

struct Node{
	bool isWord;
	Node** subNodes;
	void addSubNode(char c){
		Node* newNode = new Node;
		this->subNodes[ charToInt(c) ] = newNode;
	};
	Node(){
		subNodes = new Node*[26];
		isWord = false;
	}
	~Node(){
		for(unsigned int i = 0; i < 26; i++)
			delete subNodes[i];
		delete subNodes;
	}
};

void addWord(Node* headNode, const char* word){
	if(headNode == NULL) return;
	if(word == NULL || strlen(word) == 0 || word[0] == '\0'){
		headNode->isWord = true;
		return;
	}
	if( headNode->subNodes[ charToInt(word[0]) ] == NULL ){
		headNode->addSubNode( word[0] );
	}
	addWord( headNode->subNodes[ charToInt(word[0]) ], word+1 );
};

void checkChar(Node* dic, Node* currNode, char c, Node** nextNode){
	if( c == '\0') return;
	int i = charToInt(c);
//	printf("%c = %d \n", c, i);
	if(currNode->subNodes[ charToInt(c) ] == NULL){
		*nextNode = dic;
	}else{
		*nextNode = currNode->subNodes[ charToInt(c) ];
	}
};

int main(int argc, char** argv){

	const char* s = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < 26; i++){
		printf(" %c == %d\n", s[i], charToInt(s[i]) );
	}

	Node* dic = new Node;
	addWord(dic, "salam");
	addWord(dic, "hey");

	const char* stream = "shgysalamtrheyrsalammmmmheyhey";
	Node* currNode = dic;

	printf("checking stream = %s\n", stream);
	
	for(unsigned int i = 0; i < strlen(stream); i++){
		checkChar(dic, currNode, stream[i], &currNode);
		if( currNode->isWord )
			printf("found a word at %c , i=%d\n", stream[i], i);
	}

	delete dic;

	return 0;
}
