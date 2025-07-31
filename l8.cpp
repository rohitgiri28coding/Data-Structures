// Maximum Subarray Sum: Kadane's Algorithm

#include<iostream>
using namespace std;

int main(){
    int arr[]= {3, -4, 5, 4, -1, 7, -8};

    int size = sizeof(arr)/sizeof(int);

    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < size; i++)
    {
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);

        if(currentSum < 0){
            currentSum = 0;
        }
        
    }
    cout << "Maximum sum: " << maxSum << endl;

    return 0;
    
}