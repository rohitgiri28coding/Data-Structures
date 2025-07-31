#include <iostream>
using namespace std;

void traverseArray(int arr[], int n) {
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; // Reading
    cout << endl;
}

void writeArray(int arr[], int n, int value) {
    for (int i = 0; i < n; i++)
        arr[i] = value; // Writing
}


int main(){
    int arr[] = {1,3,4,5,6,2,4};
    int size = sizeof(arr)/sizeof(int);
    traverseArray(arr, size);
    writeArray(arr, 2, 0);
    traverseArray(arr, size);
    return 0;
}