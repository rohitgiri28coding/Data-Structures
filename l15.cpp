// Circluar LL (singly)

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*head = nullptr;

Node* createNode(int data){
    return new Node{data, nullptr};
}

void printList(){
    if(head == nullptr){
        cout << "Linked list underflow.\n";
    }
    Node* temp = head;
   do{
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void insertAtBeginning(int data)
{
    Node* newNode = createNode(data);

    if(head == nullptr){
        head=newNode;
        newNode->next=head;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    newNode->next=head;
    temp->next = newNode;
    head = newNode;
}

void insertAtPosition(int data, int position){
    Node* newNode = createNode(data);

    if(head == nullptr && position == 1){
        head = newNode;
        newNode->next = newNode;
        return;
    }
    Node *temp = head;
    for(int i =1; i != position;i++){
        if(temp->next == head){
            if((i+1) == position){
                temp->next = newNode;
                newNode->next = head;
                return;
            }
            cout << "Invalid position\n";
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp;
}

void insertAtLast(int data){
    Node *newNode = createNode(data);
    if(head == nullptr){
        head = newNode;
        newNode->next = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next!= head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    
}

void deleteAtBeginning(){
    if (head == nullptr)
    {
        cout << "Linked list underflow.\n" << endl;
        return;
    }
    Node* temp = head;
    if(temp->next != head){
        while (temp->next!=head){
            temp= temp->next;
        }
        temp->next=head->next;
        temp = head;
        head = temp->next;
        
    }else{
        head = nullptr;
    }
    
    delete(temp);

}

void deleteAtLast(){
    if (head == nullptr){
        cout << "Linked list underflow.\n" << endl;
        return;
    }
    Node* temp = head, *temp1;
    if(temp->next != head){

        while(temp->next != head){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=head;
        temp->next= nullptr;
    }else{
        head = nullptr;
    }
    delete(temp);
}

bool search(int target){
    if (head == nullptr)
    {
        cout << "Linked list underflow.\n" << endl;
        return false;
    }
    if(head->data == target){
        return true;
    }
    Node* temp = head->next;
    while(head != temp){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deallocateList() {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);

    head = nullptr;
    cout << "Deallocated list to avoid memory leaks." << endl;
}


int main(){

    insertAtBeginning(10);
    deleteAtBeginning();
    insertAtPosition(10, 1);
    printList();
    insertAtPosition(10, 2);
    insertAtLast(20);
    insertAtLast(20);
    insertAtLast(30);
    insertAtBeginning(0);
    deleteAtBeginning();
    deleteAtLast();
    if(search(20)){
        cout << "Element found\n";
    }else{
        cout << "Element not found\n";
    }

    printList();
    deallocateList();
    return 0;
}