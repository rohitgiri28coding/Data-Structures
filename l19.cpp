// Queue(using arrays)

#include<iostream>
using namespace std;

#define MAX 100

class Queue{
    int arr[MAX];
    int rear, front;

    public:
        Queue(){
            rear = front = -1;
        }

        void enqueue(int data){
            if(rear == (MAX -1)){
                cout << "Queue overflow" << endl;
                return;
            }
            if(front == -1)  front=0;
            arr[++rear]=data;
        }
        int dequeue(){
            if(front == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }
            int data = arr[front++];
            if(front > rear) 
            {
                rear = front = -1;
            }
            return data;
        }
        int getFront(){
            if(front == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }
            return arr[front];
        }
        bool isEmpty(){
            return (front == -1 || front > rear);
        }
};

int main(){

    Queue q;
    cout << q.isEmpty() << endl;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.getFront();
    q.dequeue();
    q.dequeue();
    return 0;
}
