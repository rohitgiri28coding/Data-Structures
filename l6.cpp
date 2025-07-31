#include<iostream>
using namespace std;

int main(){
    int arr[]= {1,2,4,5,6,3,5,5,7};

    int size = sizeof(arr)/sizeof(int);

    for (int i = 0; i < size; i++)
    {
        for(int j = i; j<size; j++)
        {
            for(int k = i; k<=j; k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
    
}