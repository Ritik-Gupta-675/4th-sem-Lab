#include <bits/stdc++.h>
using namespace std;
int main(){
    int size = 6;
    vector<int>arr = {2,6,4,8,9,4};
    int target;
    cout<<"Enter target sum you want to find: ";
    cin>>target;
    sort(arr.begin() , arr.end());
    int s=0;
    int e=size-1;
    bool found = false;
    while(s<=e){
        if(arr[s] + arr[e] == target){
            found = true;
            break;
        }
        else if(arr[s] + arr[e] > target)e--;
        else s++;
    }
    if(found){
        cout<<"Target sum is present: ";
        cout<<arr[s]<<" "<<arr[e];
    }
    else{
        cout<<"Target sum is not present";
    }
    return 0;
}