// Majority Element (Moore's Voting Algorithm)

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector <int> vec = { 1,3,2,3,3,7,3,3,4,3,3};


    int size = vec.size();
    int n = floor(size/2);

    int ans = 0, freq=0;
    for(int i = 0; i <size; i++){
        if (freq == 0){
            ans = vec[i];
        }
        if(ans == vec[i]){
            freq++;
        }else{
            freq--;
        }
    }

    cout << "Majority element: " << ans;

    return 0;
}

