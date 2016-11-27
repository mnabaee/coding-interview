#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


string getStrInt(int i){
	if(i == 1)
		return “1”;
	else
		return “0”;
}


void printBinaryRep(string decimalStr){
        int dotPos = decimalStr.find(".",0);
        int intPart = atoi(decimalStr.substr(0, dotPos).c_str());
        double floatPart = atof(decimalStr.substr(dotPos ).c_str());
        printf("%d .. %f\n", intPart, floatPart);


        string binStr = ".";
        while(intPart  > 0){
                binStr = getStrInt( intPart & 1 ) + binStr;
                intPart = intPart >> 1;
                //intPart = intPart >> 1;
        }


        int maxSize = 32;
        int i = 0;
        while(i < maxSize && floatPart != 0){
                floatPart *= 2;
                if(floatPart >= 1){
                        binStr += "1";
                        floatPart -=1;
                }else{
                        binStr += "0";
                }
                i++;
        }
        printf(" %s \n", binStr.c_str());
        if(floatPart != 0){
                printf("ERROR!\n");
                return;
        }
}






int main(){

   	string numStr = “23.2”;
	printBinaryRep(numStr);


        return 0;
}

