#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <cstdlib>


using namespace std;


#define N 100


int numPaths(int i, int j){
	if(i == 0 || j == 0){
	return 1;
	}else{
		return numPaths(i, j-1) + numPaths(i-1,j);
	}
}

