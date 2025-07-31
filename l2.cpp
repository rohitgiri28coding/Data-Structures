#include <iostream>
using namespace std;

// Insert at position pos (0-based index)
int insert(int arr[], int n, int value, int pos, int capacity) {
    if (n >= capacity) return n; // Can't insert: No space
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    return n + 1;
}

// Delete at position pos
int deleteAtPos(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) return n; // Invalid position
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

int main(){
    int size = 10;
    int capacity = 20;
    int arr[capacity];

    if(insert(arr, size, 10, 3, capacity) == size){
        cout << "No space";
    }else{
        size++;
    }
    if(deleteAtPos(arr, size, 3) == size){
        cout << "Invalid position";
    }else{
        size--;
    }

    return 0;
}