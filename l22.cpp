// Queue using Stack

#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
    stack <int> s1;
    stack <int> s2;

    public:

        void enqueue(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int dequeue(){
            if(s1.empty()){
                cout << "Queue underflow!\n";
                return -1;
            }
            int data = s1.top();
            s1.pop();
            return data;
        }
        int getFront(){
            if(s1.empty()){
                cout << "Queue underflow!\n";
                return -1;
            }
            return s1.top();
        }
        bool isEmpty(){
            return s1.empty();
        }

        void display() {
            if (s1.empty()) {
                cout << "Queue is empty.\n";
                return;
            }

            stack<int> temp = s1;
            stack<int> correctOrder;

            // Reverse stack to get queue order
            while (!temp.empty()) {
                correctOrder.push(temp.top());
                temp.pop();
            }

            cout << "Queue elements: ";
            while (!correctOrder.empty()) {
                cout << correctOrder.top() << " ";
                correctOrder.pop();
            }
            cout << endl;
        }  

};

int main() {
    MyQueue q;

    q.dequeue(); // Queue underflow

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();         // Output: 10 20 30
    cout << q.getFront() << endl; // Output: 10
    q.dequeue();
    q.display();         // Output: 20 30
    cout << q.isEmpty() << endl; // Output: 0
    q.dequeue();
    q.dequeue();
    q.dequeue();         // Queue underflow
    cout << q.isEmpty() << endl; // Output: 1

    return 0;
}
