// Majority Element (Brute force method)

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.


#include<iostream>
#include<vector>
using namespace std;

int main(){

    int arr[] = {1,3,2,1,1,1,1};

    int size = sizeof(arr)/ sizeof(int);
    int n = floor(size/2), idx=-1;


    for(int i = 0; i < size-1; i++){
        int freq = 0;
        for(int j = i+1; j < size; j++){
            if(arr[i] == arr[j]){
                freq++;
            }
        }
        if(freq >= n){
            idx = i;
            break;
        }
    }
    if(idx != -1)
        cout << "Majority Element: " << arr[idx] << endl;
    else
        cout << "No majority element exists.";
        
    return 0;
}
