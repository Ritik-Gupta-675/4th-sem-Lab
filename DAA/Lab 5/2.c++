#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){ 
    cout<<node<<" ";
    visited[node] = true; 
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited);
        }}}
void dfsStack(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            cout << node << " ";  
            visited[node] = true;}
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);}} }
}
int main(){
    vector<vector<int>>adj(10);
    adj[1] = {2,3};adj[2] = {1,3,4,5};adj[3] = {1,2,6};adj[4] = {2,5};
    adj[5] = {2,4,6,7};adj[6] = {3,5,8,9};adj[7] = {5,8};adj[8] = {6,7};adj[9] = {6};
    vector<bool>visited(10,false);
    int i;
    cout<<"Enter Node to start: ";
    cin>>i;
    cout<<"Dfs using recussion: ";
    dfs(i,adj,visited);
    vector<bool>visited2(10,false);
    cout<<"\nDfs using stack: ";
    dfsStack(i,adj,visited2);
}