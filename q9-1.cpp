#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


void merge(int* A, int* B, int sizeA, int sizeB){
	int i = 0;
	int j = 0;
	int buff = A[0];
	while(i < sizeA + sizeB){
if( buff > B[j] ){
	//insert B[j] at A[i] and shift A to right
			A[i] = B[j];
	j++;
}else{
	A[i] = buff;
}
i++;
if(i >= sizeA + sizeB){
	break;
}else{
	buff = A[i];
}
}


}
