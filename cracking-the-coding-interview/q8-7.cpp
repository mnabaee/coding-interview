#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


int numWays(int n, int coin = 25){
	int next_coin = 0;
	switch(coin){
		case 25: next_coin = 10; break;
		case 10: next_coin = 5; break;
		case 5: next_coin = 1; break;
		default: return 1;
	}
	int sum  = 0;
	for(unsigned int i = 0; i * coin <= n ; i++){
		sum += numWays(n - i*coin, next_coin);
	}
	return sum;
};
