// Majority Element

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int arr[] = {1,1,3,41,2,3,4,3,4,4,5,5};
    int size = sizeof(arr)/sizeof(int);

    
    vector<int> vec, freq;

    for(int num: arr){
        bool flag = true;
        if(!vec.empty()){
            for(int n: vec){
                if(num == n){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            vec.push_back(num);
            freq.push_back(0);
        }
    }

    for(int i = 0; i< vec.size();i++){
        for(int num: arr){
            if(vec[i] == num){
                freq[i]++;
            }
        }
    }
    int maxIdx, maxFreq=0;
    for(int i = 0; i < freq.size(); i++){
        if(maxFreq<freq[i]){
            maxIdx=i;
            maxFreq = freq[i];
        }
    }

    cout << "Majority Element = " << vec[maxIdx] << " with frequency of " << maxFreq << ".";


    return 0;
}
