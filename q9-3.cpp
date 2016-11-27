#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


bool hasElement( int* array, int i, int j, int val ){
	if(i>j) return false;
	if(i == j && array[i] == val) return true;
	else if(i ==j && array[i] ~= val) return false;


	if( array[i] <= array[j] )
		if( array[i] <= val && val <= array[j] ) return true;
		else return false;
	else
		if( array[i] >= val && val >= array[j] ) return true;
		else return false;
}


int findElement(int* array, int i, int j, int val){
	int k = (i+j)/2;
	if( hasElement(array, i, k, val) ){
		return findElement(array, i, k, val);
	} else if( hasElement(array, k+1, j, val) ){
		return findElement(array, k+1, j, val);
	} else return -1;
}

