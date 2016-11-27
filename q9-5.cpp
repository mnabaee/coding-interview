#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


int findString(vector<string> & array, string str){
	int i = 0; 
	int j = array.length() - 1;
	while( i < j){
while( array[i] == “” ) i++;
while( array[j] == “” ) j--;
int k0 = (i+j)/2;
int k = k0;
while(array[k] == “”) k--;
if( array[i] == str) return i;
if( array[i] == str) return i;
if( array[k] == str) return k;
if( array[i] < str && str < array[k] ){
	j = k;
}else if( array[k] < str && str < array[j]) {
	i = k;
}else return -1;
	}




}
