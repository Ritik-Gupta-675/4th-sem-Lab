#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int destination;
    int weight;
};
class Graph {
private:
    int numVertices;
    vector<list<Edge>> adjList;
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }
    void addEdge(int source, int destination, int weight) {
        if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
            adjList[source].push_back({destination, weight});
            adjList[destination].push_back({source, weight});
        }
    }
    void displayGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " is connected to: ";
            for (const auto& edge : adjList[i]) {
                cout << edge.destination << " (weight: " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
    int getNumVertices() {
        return numVertices;
    }
    const list<Edge>& getAdjList(int vertex) {
        if (vertex >= 0 && vertex < numVertices) {
            return adjList[vertex];
        }
        static list<Edge> emptyList;
        return emptyList;
    }
    void primAlgorithm() {
        vector<int> parent(numVertices, -1);   
        vector<int> key(numVertices, INT_MAX);
        vector<bool> inMST(numVertices, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (inMST[u]) continue; 
            inMST[u] = true;
            for (const Edge& edge : adjList[u]) {
                int v = edge.destination;
                int weight = edge.weight;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        cout << "\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n";
        for (int i = 1; i < numVertices; i++) {
            cout << "Edge: " << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
        }
    }
};
int main() {
    Graph graph(7);
    graph.addEdge(0,1,28);graph.addEdge(0,5,10); graph.addEdge(5,4,25);graph.addEdge(4,3,22);
    graph.addEdge(3,2,12);graph.addEdge(2,1,16);graph.addEdge(6,3,18);graph.addEdge(6,4,24);graph.addEdge(6,1,14);
    cout << "Original graph:" << endl;
    graph.displayGraph();
    graph.primAlgorithm();
    return 0;
}