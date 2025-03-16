#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}
void topologicalSort(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main() {
    int v=6;
    vector<vector<int>> adj(v);
    adj ={{},{},{3},{1},{0,1},{0,2}};
    cout << "Topological Sort Order: ";
    topologicalSort(v, adj);
    return 0;
}
