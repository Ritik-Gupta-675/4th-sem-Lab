#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[] , int n){
    for(int i =n-1;i>0;i--){
        int max_idx = i;

        for(int j = 0;j<i;j++){
            if(arr[j] > arr[max_idx]){
                max_idx = j;
            }
        }
        swap(arr[max_idx],arr[i]);
    }
}

void print(int arr[] ,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[6] = {3,9,4,5,8,1};
    int n = 6;
    print(arr,n);
    selectionsort(arr,n);
    print(arr,n);
}