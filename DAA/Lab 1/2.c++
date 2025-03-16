#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[] , int n){
    int count =0;
    for(int i =0;i<n-1;i++){
        int min_idx = i;

        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
                
            }
            count++;
        }
        swap(arr[min_idx],arr[i]);
    }

    cout<<count<<endl;
}
void print(int arr[] ,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[5] = {3,8,2,5,1};
    int n = 5;
    print(arr,n);
    selectionsort(arr,n);
    print(arr,n);
}