#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


list<string> findPermutations(string input){
	list<string> result;
	if( input.length() == 1 ) {
		result.push_back(input);
		return result;
	}
	buff = findPermutations( input.substr(1) );
	for(unsigned int i = 0; i < buff.size(); i++){
		for(unsigned int j = 0; j < input.length(); j++){
			string concatStr = buff[i];
			concatStr.insert(j, input.at(0) );
			result.push_back( buff[i] );
		}
	}
}


list<string> findPermutationsIter(string input){
	list<string> result, buff;
	string str = “”;
	buff.push_back(str);
	for(unsigned int i = 0; i < input.length(); i++){
		for(unsigned int j = 0; j < buff.size(); j++){
			for(unsigned k = 0; k < i + 1; k++){
				str = buff[j];
				str.insert(k, input.at(i) );
				result.push_back(str);
			}
		}
		buff = result;
	}
return	result;
	
}
