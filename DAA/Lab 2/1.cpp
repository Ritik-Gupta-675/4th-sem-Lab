#include <iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j= low; j<high ; j++){
        if(pivot>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i+1;
}
void quicksort(int arr[] , int low , int high){
    if(low<high){
        int pivot = partition(arr,low,high);

        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[5] = {3,1,5,6,2};
    int n = 5;
    print(arr,n);
    quicksort(arr,0,n-1);
    cout<<"Pivot at end: ";
    print(arr,n);
}