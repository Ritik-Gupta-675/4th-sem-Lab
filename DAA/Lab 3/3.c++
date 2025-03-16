#include<bits/stdc++.h>
using namespace std;
int findk(int arr[] , int size , int k){
    for(int i = 0; i<k ; i++){
        int maxi = INT_MIN;
        int max_idx = -1;
        for(int j = 0 ; j<size ; j++){
            if(arr[j] > maxi){
                maxi = arr[j];
                max_idx = j;
            }
            if(i == k-1){
                return maxi;
            }
        }
        arr[max_idx] = INT_MIN;
    }
    return -1;
}
int main(){
    int arr[6] = {2,5,6,3,8,1};
    int n = 6;
    int k;
    cout<<"Enter value for k: ";
    cin>>k;

    int ans = findk(arr,n,k);

    cout<<"The Kth largest element is: "<<ans;

}