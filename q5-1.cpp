#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


int setBits(int N, int M, int i, int j){
	int Mshifted = M << (i-1);
	int window = ~0;
	int window2 = ~0;
	window = window >> (32-j+1);
	window2 = window2 << (i-1);
	window = window & (window2);
	return Mshifted + (~window) & N;
}
