#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


int A[]= {0, 1, 3, 2, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int n = 15;
int size = 4;


int getBit(int Ai, int bitIndex){
        return (A[Ai] >> bitIndex) & 1;
}


int findMissing(){
        int missingNum = 0;
        for(int index = 0; index < size; index++){
                //count the number of integers with 0 at the index
                int num1owners = 0;
                int num0owners = 0;
                for(int i = 0; i <= n-1; i++){
                        if(getBit(i, index) == 1)
                                num1owners++;
                        else
                                num0owners++;
                }
                printf("%d- %d\n", num1owners, num0owners);
                if(num1owners > num0owners){
                        missingNum += (0 << index );
                }else{
                        missingNum += (1 << index );
                }
        }
        return missingNum;
}


int main(){


        printf(" %d  \n", findMissing());


        return 0;
}

