// Singly Linked list

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*head = nullptr;


void printList(){
    if(head==nullptr){
        cout << "Linked list is empty." << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp=temp->next;
    }
    cout << "null" << endl;
}

Node* createNode(int data){
    Node* newNode = new Node{data, nullptr};
    return newNode;
}

void insertAtBeginning(int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;

}

void insertAtEnd(int data){
    Node* newNode = createNode(data);
    if(head==nullptr){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp -> next;
    }
    temp->next = newNode;
}
void deleteAtBeginning(){
    if(head==nullptr){
        cout << "Linked list is empty. No nodes to delete!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete(temp);

}

void deleteAtLast(){
    if(head==nullptr){
        cout << "Linked list is empty. No nodes to delete!" << endl;
        return;
    }else if (head->next == nullptr){
        Node* temp = head;
        head = nullptr;
        delete(temp);
    }else{
        Node *temp = head, *temp1 = head->next;
        while(temp1->next != nullptr){
            temp = temp1;
            temp1=temp1->next;

        }
        temp->next = nullptr;
        delete(temp1);
    }
}

bool search(int target){
    if(head==nullptr){
        cout << "Linked list is empty." << endl;
        return false;
    }
    Node *temp = head;
    while(temp != nullptr){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main(){
    
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(120);

    if(search(10)){
        cout << "Element found" << endl;
    }else{
        cout << "Element not found" << endl;
    }
    printList();

    deleteAtBeginning();
    deleteAtLast();
    printList();


    return 0;

}