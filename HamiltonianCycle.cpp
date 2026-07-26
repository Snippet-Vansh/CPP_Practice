#include <iostream>
using namespace std;

#define V 5

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

bool isSafe(int v, int pos)
{
    // Check if current vertex is adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex is already included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int pos)
{
    // All vertices are included
    if (pos == V)
    {
        // Check if last vertex connects to first
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            if (hamCycleUtil(pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle()
{
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start from vertex 0

    if (!hamCycleUtil(1))
    {
        cout << "No Hamiltonian Cycle exists";
        return false;
    }

    cout << "Hamiltonian Cycle:\n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";

    cout << path[0]; // Return to start
    return true;
}

int main()
{
    hamCycle();
    return 0;
}