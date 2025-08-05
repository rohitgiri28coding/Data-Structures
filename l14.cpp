// Doubly linked list

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
}*head = nullptr;


Node* createNode(int data){
   return new Node{data, nullptr, nullptr};
}
void printLinkedList(){
    if(head == nullptr){
        cout << "Linked list underflow!" << endl;
        return;
    }
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void printLinkedListBackward(){
    if(head == nullptr){
        cout << "Linked list underflow!";
        return;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    while(temp!=nullptr){
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
}

void insertAtBeginning(int data){
    Node *newNode = createNode(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }
}

void insertAtEnd(int data){
    Node *newNode = createNode(data);
    if(head ==  nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp-> next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int data, int position){
    Node *newNode = createNode(data);
    if(position == 1){
        newNode->next = head;
        head = newNode;
        if(newNode->next!= nullptr){
            newNode->next->prev = nullptr;
        }
        return;
    }
    Node* temp = head;
    
    for(int i = 1; i != position; i++){
        if(temp->next == nullptr ){
            if(i+1 == position){
                temp->next= newNode;
                newNode->prev=  temp; 
            }else{
                cout << "Invalid position" << endl;

                return;
            }
        }
        temp = temp->next;
    }

    
}

void deleteAtBeginning(){
    if(head == nullptr){
        cout << "Linked List underflow." << endl;
        return;
    }
    Node* temp = head;
    if(temp->next != nullptr){
        temp->next->prev = nullptr;
        head = temp->next;
    }
    temp->next = nullptr;
    delete(temp);
}
void deleteAtLast(){
    if(head == nullptr){
        cout << "Linked List underflow." << endl;
        return;
    }
    Node* temp = head;
    if(head->next == nullptr){
        head = nullptr;
    }else{
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next= nullptr;
        temp->prev = nullptr;
    }
    delete(temp);
}
void deleteAtPosition(int position){
    if(head == nullptr){
        cout << "Linked List underflow." << endl;
        return;
    }
    Node* temp = head;
    if(position == 1){
        head = temp->next;
        if(temp->next!= nullptr){
            temp->next->prev=nullptr;
            temp->next= nullptr;
        }
        delete(temp);
        return;
    }
    for(int i = 1; i != position; i++){
        if(temp == nullptr){
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
    }
    temp->prev->next= temp->next;
    if(temp->next!=nullptr){
        temp->next->prev = temp ->prev;
       temp->next=nullptr;
    }
    temp->prev=nullptr;

}
bool searchList(int target){
    if(head == nullptr){
        cout << "Linked List underflow." << endl;
        return false;
    }
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == target){
            return true;
        }
        temp=temp->next;
    }   
    return false;
}
void dellocateList(){
    while(head!=nullptr){
        Node *temp = head;
        head = temp->next;
        delete(temp);
    }
    cout << "Deallocated list to avoid memory leaks." << endl;
}

int main(){
    
    insertAtBeginning(10);
    insertAtPosition(20, 2);
    printLinkedList();
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtEnd(0);
    insertAtPosition(50, 3);
    deleteAtBeginning();
    deleteAtLast();
    deleteAtPosition(2);
    printLinkedList();
    printLinkedListBackward();
    if(searchList(20)){
        cout << "Element found!"<< endl;
    }else{
        cout << "Element not found!" << endl;
    }
    dellocateList();

    return 0;
}