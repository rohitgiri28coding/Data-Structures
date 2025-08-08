// Circluar Queue

#include <iostream>
using namespace std;

#define MAX 100

class CircularQueue{
    int arr[MAX];
    int rear, front, currSize;

    public:
        CircularQueue(){
            rear = front = -1;
            currSize = 0;
        }

        void enqueue(int data){
            if(currSize == MAX){
                cout << "Queue overflow" << endl;
                return;
            }
            rear = (rear + 1) % MAX;
            arr[rear] = data;
            if(front == -1) front=0;
            currSize++;
        }
        int dequeue(){
            if(currSize == 0){
                cout << "Queue underflow" << endl;
                return -1;
            }
            int data = arr[front];
            front = (front+1) % MAX;
            currSize--;
            if(currSize == 0) front = rear = -1;
            return data;
        }
        int getFront(){
            if(currSize == 0){
                cout << "Queue underflow" << endl;
                return -1;
            }
            return arr[front];
        }
        bool isEmpty(){
            return (currSize==0);
        }
         void display() {
            if (currSize == 0) {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "Queue elements: ";
            int i = front;
            for (int count = 0; count < currSize; count++) {
                cout << arr[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
};



int main() {
    CircularQueue q;

    q.dequeue();         // Underflow
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();         // Should print: 10 20 30

    cout << q.getFront() << endl; // Should print: 10

    q.dequeue();         // Removes 10
    q.display();         // Should print: 20 30

    cout << q.isEmpty() << endl; // Should print: 0

    return 0;
}
