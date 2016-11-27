
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


void sortStack(stack<int>* stackk){
        if( stackk->empty() ){
                return;
        }
        int top = stackk->top();
        stackk->pop();


        sortStack(stackk);


        stack<int> buffStack;
        while( !stackk->empty() && top <= stackk->top()){
                buffStack.push( stackk->top() );
                stackk->pop();
        }
        stackk->push( top );
        while( !buffStack.empty() ){
                stackk->push( buffStack.top() );
                buffStack.pop();
        }
}






int main(){


        stack<int> myStack;
        myStack.push(2);
        myStack.push(1);
        myStack.push(1);
        myStack.push(4);
        myStack.push(3);
        myStack.push(9);


        sortStack(&myStack);


        while(!myStack.empty()){
                printf("%d-", myStack.top());
                myStack.pop();
        }


        return 0;
}




++++++++++++++++++++++++++++++++++++


#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>


using namespace std;


void sortStack(stack<int>* st){


        stack<int> buffSt;
        while( ! st->empty() ){
                printf("1\n");
                int tmp = st->top();
                st->pop();
                while( ! buffSt.empty() &&  tmp > buffSt.top() ){
                        printf("2\n");
                        st->push(buffSt.top());
                        buffSt.pop();
                }
                buffSt.push(tmp);
        }


        while( ! buffSt.empty() ){
                st->push(buffSt.top());
                buffSt.pop();
        }


}




int main(){


        stack<int> myStack;
        myStack.push(2);
        myStack.push(1);
        myStack.push(1);
        myStack.push(4);
        myStack.push(3);
        myStack.push(9);


        sortStack(&myStack);


        while(!myStack.empty()){
                printf("%d-", myStack.top());
                myStack.pop();
        }


        return 0;
}


