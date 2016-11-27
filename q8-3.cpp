#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <cstdlib>


using namespace std;


void getSubsets(int* array, int size, list< list<int>* > & result){
	if(size == 0){
		result.clear();
		result.push_back(new list<int>());
		return;
	}
	getSubsets(array, size - 1, result);
	unsigned int size = result.size();
	for(unsigned int i = 0; i < size; i++){
		list<int>* newSubSet = new list<int>;
		*newSubSet = *result[i];
		newSubSet->push_back(array[size - 1]);
		result.push_back(newSubSet);
	}
}


void getSubSetsIter(int* array, int size, list< list<int> * > & result){
	result.clear();
	result.push_back(new list<int>() );


	for(unsigned int i = 0; i < size; i++){
		unsigned int size = result.size();
		for(unsigned int j = 0; j < size; j++){
			list<int> * newSubSet = new list<int>;
			*newSubSet = *result[j];
			newSubSet->push_back( array(i) );
			result.push_back(newSubSet);
		}
	}
	return;
}
