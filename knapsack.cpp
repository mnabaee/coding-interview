#include <stdlib.h>
#include <stdio.h>

using namespace std;



int findMax(int* w, int* v, int n, int W, bool*** put){
	int** values = new int*[n + 1];
	for( int u = 0; u < n+1; u++)
		values[u] = new int[W + 1];

	for( int i = 0; i < n; i ++ ){
		for( int wi = 0; wi < W + 1; wi++ ){
			if( wi == 0 ){
				(*put)[i][wi] = false;
				values[i][wi] = 0;
			}else if( i == 0 ){
				if( wi > w[0]){
					(*put)[0][wi] = true;
					values[0][wi] = v[0];
				}else{
					(*put)[0][wi] = false;
					values[0][wi] = 0;
				}	
			}else if( wi <= w[i] || values[i-1][ wi] > values[i-1][ wi - w[i] ] + v[i] ){
				//printf(" %d %d %d\n", values[i-1][wi], values[i-1][wi-w[i] ] , v[i]);
				(*put)[i][wi] = false;
				values[i][wi] = values[i-1][wi]; 
			}else{
				(*put)[i][wi] = true;
				values[i][wi] = values[i-1][wi - w[i] ] + v[i];
			}
			printf("%d - ", values[i][wi]);
		}
		printf("\n");
		
	}
	return values[n-1][W];	
}	

int main(int argc, char** argv){

	unsigned int n = 3;
	int w[] = {1, 3, 4};
	int v[] = {60, 40, 70};
	int W = 5;
	if(argc > 1)
		W = atoi(argv[1]);

	for(int u = 0; u < n; u++){
		printf("w=%d, v=%d  \n", w[u], v[u]);
	}

	bool** put = new bool*[n];
	for(int u = 0; u < n; u++)
		put[u] = new bool[W];	

	int res = findMax(w, v, n, W, &put);
	printf("res=%d\n", res);

	return 0;
}

