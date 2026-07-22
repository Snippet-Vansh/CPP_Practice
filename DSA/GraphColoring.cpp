#include <iostream>
using namespace std;

#define V 4

bool isSafe(int graph[V][V], int color[], int v, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(graph, color, v, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0; // Backtrack
        }
    }

    return false;
}

bool graphColoring(int graph[V][V], int m)
{
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0))
    {
        cout << "Solution does not exist";
        return false;
    }

    cout << "Assigned Colors:\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " --> Color " << color[i] << endl;

    return true;
}

int main()
{
    int graph[V][V] =
    {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int m = 3;

    graphColoring(graph, m);

    return 0;
}