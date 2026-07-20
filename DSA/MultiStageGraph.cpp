#include <iostream>
#include <climits>
using namespace std;

const int N = 8;

int main() {
    int cost[N][N] = {
        {0,1,2,5,0,0,0,0},
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0}
    };

    int dist[N];
    int path[N];

    dist[N - 1] = 0;

    // Compute minimum cost from last node to first
    for (int i = N - 2; i >= 0; i--) {
        dist[i] = INT_MAX;

        for (int j = i + 1; j < N; j++) {
            if (cost[i][j] != 0 && cost[i][j] + dist[j] < dist[i]) {
                dist[i] = cost[i][j] + dist[j];
                path[i] = j;
            }
        }
    }

    cout << "Minimum Cost = " << dist[0] << endl;

    cout << "Path: ";
    int i = 0;
    cout << i + 1;
    while (i != N - 1) {
        i = path[i];
        cout << " -> " << i + 1;
    }

    return 0;
}