#include<iostream>
using namespace std;

void reverseArrayIter(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}


void reverseArrayRec(int arr[], int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseArrayRec(arr, start + 1, end - 1);
}

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    for (int i = 0; i < n1; i++)
        merged[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        merged[n1 + i] = arr2[i];
    // For sorted merge: use a merge step as in Merge Sort
}
