// Queue (Using LL)

#include<iostream>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;

    QueueNode(int da){
        data = da;
        next = NULL;
    }
};

class Queue{
    QueueNode *front, *rear;

    public:
        Queue(){
            front=rear= nullptr;
        }

        void enqueue(int data)
        {
            QueueNode *newNode = new QueueNode(data);
            if(front == nullptr){
                front = rear = newNode;
            }else{
                rear->next = newNode;
                rear = newNode;
            }
        }
        int dequeue()
        {
            if(front == nullptr){ 
                cout << "Queue underflow." << endl;
                return -1;
            }
            int data = front->data;
            QueueNode *temp = front;
            if(front == rear){
                front = rear = nullptr;
            }else{
                front = front->next;
            }
            delete(temp);
            return data;
        }
        int getFront(){
            if(front == nullptr){ 
                cout << "Queue underflow." << endl;
                return -1;
            }
            return (front->data);
        }
        bool isEmpty(){
            return (front == nullptr);
        }

};

int main(){

    Queue q;
    q.dequeue();
    q.enqueue(10);
    cout << q.getFront() << endl;
    cout << q.isEmpty() << endl;
    q.dequeue();
    cout << q.isEmpty();

    return 0;
}