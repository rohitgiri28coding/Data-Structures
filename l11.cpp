// Majority Element (Brute force method -- Optimized - Using Sorting)

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.


#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector <int> vec = {1,2,3,4,0,80,0,0,7,0,0,0};

    int size = vec.size();

    int n = floor(size/2);

    sort(vec.begin(), vec.end());
   
    int freq = 1, ans = vec[0];

    for(int i = 0; i<size-1; i++){
        if(vec[i]==vec[i+1]){
            freq++;
        }
        else{
            if(freq >= n){
                cout << "Majority element: " << vec[i] << " with frequency = " << freq;
                break;
            }
            freq = 1;
        }
    }
    

    return 0;
}
