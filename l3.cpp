#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}


int main(){
    int arr[] = {1,3,4,5,6,2,4};
    int size = sizeof(arr)/sizeof(int);

    if(linearSearch(arr, size, 3) == -1){
        cout << "Element not found";
    }else{
        cout << "Element found";
    }

    bubbleSort(arr, size);
    if(binarySearch(arr, size, 3) == -1){
        cout << "Element not found";
    }else{
        cout << "Element found";
    }

    return 0;
}
