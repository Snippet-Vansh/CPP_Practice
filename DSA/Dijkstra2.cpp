#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    // Distance array initialized to infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min-heap (priority queue) storing {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Skip if we already found a shorter path
        if(d > dist[u]) continue;

        // Relax edges
        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5; // number of vertices
    vector<vector<pair<int,int>>> adj(V);

    // Example graph (directed, weighted)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int src = 0; // starting node
    vector<int> dist = dijkstra(V, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX) cout << "Node " << i << " : INF\n";
        else cout << "Node " << i << " : " << dist[i] << "\n";
    }

    return 0;
}
