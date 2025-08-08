// Stack Using Queue

#include<iostream>
#include<queue>
using namespace std;

class MyStack{
    queue <int> q1;
    queue <int> q2;

    public:
        MyStack(){

        }

        // Here we can also make push 0(1) which will maek pop O(n)
        void push(int x){   // O(n)
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

        void pop(){     // O(1)
            if (q1.empty()) {
                cout << "Stack underflow" << endl;
                return;
            }
            q1.pop();
        }
        int top(){
            if (q1.empty()) {
                cout << "Stack underflow" << endl;
                return -1;
            }
            return q1.front();
        }
        bool isEmpty(){
            return q1.empty();
        }
        void display() {
            if (q1.empty()) {
                cout << "Stack is empty" << endl;
                return;
            }

            cout << "Stack (top to bottom): ";
            queue<int> temp = q1;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
};

int main() {
    MyStack s;

    s.pop();                  // Stack underflow
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();              // Should show 30 20 10
    cout << s.top() << endl;  // 30
    s.pop();
    cout << s.top() << endl;  // 20
    cout << s.isEmpty() << endl; // 0 (false)

    s.pop();
    s.pop();
    s.pop();                  // Stack underflow
    cout << s.isEmpty() << endl; // 1 (true)

    return 0;
}
