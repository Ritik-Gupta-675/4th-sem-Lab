#include <bits/stdc++.h>
using namespace std;
void bfs(int node,vector<vector<int>>&adj,vector<bool>&visited){ 
    queue<int>q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto i:adj[curr]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            } } }}
int main(){
    vector<vector<int>>adj(10);
    adj[1] = {2,3};adj[2] = {3,4,5};adj[3] = {1,2,6};adj[4] = {2,5};
    adj[5] = {2,4,6,7};adj[6] = {3,5,8,9};adj[7] = {5,8};adj[8] = {6,7};adj[9] = {6};
    vector<bool>visited(10,false);
    int i;
    cout<<"Enter Node to start with: ";
    cin>>i;
    bfs(i,adj,visited);
}