#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


list<string> getValidParentheses(int num){
	list<string> results;
	if(num == 1){
		results.push_back(“()”);
	}
	list<string> buff = getValidParentheses(num - 1);
	for(unsigned int i = 0; i < buff.size(); i++){
		for(unsigned j = 0; j <= buff[i].length(); j++){
			string str1 = buff[i];
			str1.insert(j, “(” );
			int numLeft = 0;
			int numRight = 0;
			for(unsigned int k = 0; k <= str1.length(); k++){
				string str2 = str1;
				if(numLeft >= numRight + 1){
					str2.insert(k, “)” );
					results.push_back(str2);
				}
if(k == str1.length()) break;
				if(str1.at(k) == “(”){
					numLeft++;
				}else{
numRight ++;
				}
			}
		}


	}




}
