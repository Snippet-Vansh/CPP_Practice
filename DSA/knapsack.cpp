#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimized 0/1 Knapsack using 1D DP
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Traverse backwards to avoid overwriting values we still need
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> wt(n), val(n);
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}
