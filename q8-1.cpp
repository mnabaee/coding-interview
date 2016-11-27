#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <cstdlib>


using namespace std;


typedef long long ll;


ll Fib(int n){
	if(n < 0) return -1;
if(n == 1) return 1;
return Fib(n-1) + Fib(n-2);
}


ll FibIter(int n){
	if(n <= 0) return -1;
	if(n == 1) return 1;
	ll a = 0;
	ll b = 1;
	for(int i = 2; i < n; i++){
		ll c = a + b;
		a  = b;
		b = c;
	}
	return b;
}
