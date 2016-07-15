#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool isVowel(char c){
	return (c == 'a' ||
		c == 'o' ||
		c == 'e' ||
		c == 'i'  );
}

int main(int argc, char** argv){

	char newStr[strlen(argv[1])];
	strcpy(newStr, argv[1]);
	
	printf(" newStr=%s \n", newStr);

	unsigned int i,j;
	i = 0;
	j = strlen(newStr) - 1;
	while(i <= j){
		bool iV = isVowel(newStr[i]);
		bool jV = isVowel(newStr[j]);
		if( iV && jV ){
			char temp = newStr[j];
			newStr[j] = newStr[i];
			newStr[i] = temp;
			i++;
			j--;
		}else if( iV && !jV ){
			j--;
		}else if( !iV && jV ){
			i++;
		}else{
			i++;
			j--;
		}
	}

	printf(" strstr=%s \n", newStr);
	return 0;
}

