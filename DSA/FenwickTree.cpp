#include <iostream>
using namespace std;

class FenwickTree {
    int BIT[1000];
    int n;

public:
    FenwickTree(int size) {
        n = size;
        for (int i = 0; i <= n; i++)
            BIT[i] = 0;
    }

    // Update value at index
    void update(int index, int value) {
        while (index <= n) {
            BIT[index] += value;
            index += index & (-index);
        }
    }

    // Prefix sum from 1 to index
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }

    // Range Sum (left to right)
    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    int arr[] = {0, 2, 1, 1, 3, 2, 3, 4, 5, 6}; // 1-based indexing
    int n = 9;

    FenwickTree ft(n);

    // Build Fenwick Tree
    for (int i = 1; i <= n; i++)
        ft.update(i, arr[i]);

    cout << "Prefix Sum till index 5 = " << ft.query(5) << endl;

    cout << "Sum from index 3 to 7 = "
         << ft.rangeQuery(3, 7) << endl;

    // Update index 4 by +2
    ft.update(4, 2);

    cout << "After Update:" << endl;
    cout << "Prefix Sum till index 5 = "
         << ft.query(5);

    return 0;
}