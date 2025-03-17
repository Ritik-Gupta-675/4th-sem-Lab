#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[] , int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        bool swapped = false;

        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            count++;
        }

        if(!swapped){break;}
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
    int arr[7] = {7,18,5,10,3,2,1};
    int n = 7;
    print(arr,n);
    bubblesort(arr,n);
    print(arr,n);
}