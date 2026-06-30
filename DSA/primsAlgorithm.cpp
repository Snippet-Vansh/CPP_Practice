#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

void primMST(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;
        totalWeight += key[i];
    }

    cout << "Total Weight = " << totalWeight << endl;
}

int main() {
    int V = 5;

    vector<vector<pii>> adj(V);

    // Adding edges (Undirected Graph)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    primMST(V, adj);

    return 0;
}