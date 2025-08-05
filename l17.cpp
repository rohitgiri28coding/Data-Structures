#include<iostream>
using namespace std;

struct Stack{
    int data;
    Stack* next;

    Stack(int da, Stack* ne){
        data = da;
        next = ne;
    }
};

class StackList{
    Stack *head;

    public:

        StackList(){
            head=nullptr;
        }
        
        void push(int x){
            Stack* newNode = new Stack{10, head};
            head = newNode;
        }
        int pop(){
            if(head == nullptr){
                cout << "Stack underflow!\n";
                return -1;
            }
            Stack* temp = head;
            head = temp->next;
            int data = temp->data;
            delete(temp);
            return data;
        }
        int peek(){
            if(head == nullptr){
                cout << "Stack underflow!\n";
                return -1;
            }
            return head->data;
        }
        bool isEmpty(){
            return (head == nullptr);
        }
};

int main(){
    StackList s;
    cout << "Is empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.push(10);
    s.push(20);
    s.push(30);


    cout << "Top element: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;

    return 0;
}
