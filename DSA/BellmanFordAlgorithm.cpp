#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 1; i <= V-1; i++) {
        for(auto &edge : edges) {
            if(dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for(auto &edge : edges) {
        if(dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for(int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int V = 5, E = 8;
    vector<Edge> edges;
    edges.push_back({0,1,-1});
    edges.push_back({0,2,4});
    edges.push_back({1,2,3});
    edges.push_back({1,3,2});
    edges.push_back({1,4,2});
    edges.push_back({3,2,5});
    edges.push_back({3,1,1});
    edges.push_back({4,3,-3});

    bellmanFord(V, E, edges, 0);
    return 0;
}
