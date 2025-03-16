#include <iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int j = high;
    for (int i = high; i > low; i--) {
        if (arr[i] > pivot){
            swap(arr[i],arr[j]);
            j--;
        }
    }
    swap(arr[j],arr[low]);
    return j;
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
    int arr[5] = {13,1,15,6,2};
    int n = 5;
    print(arr,n);
    quicksort(arr,0,n-1);
    cout<<"Pivot at start: ";
    print(arr,n);
}