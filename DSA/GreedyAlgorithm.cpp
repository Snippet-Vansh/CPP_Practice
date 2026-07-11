#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
};

// Comparison function to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, std::vector<Item>& items) {
    // 1. Sort items by value/weight ratio
    std::sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value accumulated in the knapsack

    for (const auto& item : items) {
        // If the item can fit completely, take it
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } 
        // If it can't fit completely, take the fractional part
        else {
            totalValue += item.value * ((double)W / (double)item.weight);
            break; // The knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int maxWeight = 50; // Knapsack capacity
    std::vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    double maxVal = fractionalKnapsack(maxWeight, items);

    std::cout << "Maximum value we can obtain = " << maxVal << std::endl;
    return 0;
}