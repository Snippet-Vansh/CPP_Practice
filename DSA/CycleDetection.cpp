#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, graph, visited))
                return true;
        }
        else if (neighbor != parent)
            return true;
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);

    graph[0]={1};
    graph[1]={0,2};
    graph[2]={1,3};
    graph[3]={2,4};
    graph[4]={3};

    vector<bool> visited(V,false);

    if(dfs(0,-1,graph,visited))
        cout<<"Cycle Found";
    else
        cout<<"No Cycle";
}