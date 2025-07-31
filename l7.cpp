// Maximum Subarray Sum: Brute force Approach

#include<iostream>
using namespace std;

int main(){
    int arr[]= {3, -4, 5, 4, -1, 7, -8};

    int size = sizeof(arr)/sizeof(int);

    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int currentSum = 0;
        for(int j = i; j<size; j++)
        {
           currentSum += arr[j];
           maxSum = max(currentSum, maxSum);
        }
    }
    cout << "Maximum sum: " << maxSum << endl;

    return 0;
    
}