// Stack (using Array)

#include<iostream>
using namespace std;

#define MAX 100

class Stack{
    int arr[MAX];
    int topIdx;

    public:

        Stack(){
            topIdx = -1;
        }

        void push(int x){
            if(topIdx >= MAX-1){
                cout << "Stack Overflow!";
                return;
            }
            arr[++topIdx] = x;
        }
        int pop(){
            return arr[topIdx--];
        }
        int peek(){
            if (topIdx < 0) {
            cout << "Stack is Empty\n";
            return -1;
            }
            return arr[topIdx];
        }
        bool isEmpty(){
            return (topIdx==-1);
           
        }
};

int main(){

    Stack sc;
    sc.peek();
    sc.isEmpty();
    sc.push(10);
    sc.push(20);
    cout << sc.pop();


    return 0;
}