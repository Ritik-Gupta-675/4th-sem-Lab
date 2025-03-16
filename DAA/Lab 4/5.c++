#include <bits/stdc++.h>
using namespace std;
    void next_height(vector<int>arr,vector<int>&ans){
        stack<int>st;
        for(int i =arr.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty())ans[i] = -1;
            else ans[i]=st.top();
            st.push(arr[i]);
        }
    }
int main(){
    vector<int> arr = {3,38,2,6,8,30,12};
    vector<int> ans(arr.size());
    next_height(arr,ans);
    cout<<"Next max height is: ";
    for(int i :ans){
        cout<<i<<" ";
    }
}