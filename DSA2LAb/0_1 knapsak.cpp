#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

int main() {
    // Define items
    Item items[] = {
        {"Swords of Zoro", 15, 800},
        {"Meat (for Luffy)", 5, 200},
        {"Chopper's Medical Kit", 5, 500},
        {"Nami's Log Pose", 10, 300},
        {"Sanji's Ingredients", 5, 600},
        {"Franky’s Tools", 10, 700},
        {"Robin’s Books", 10, 400}
    };

    int maxWeight = 50; // Maximum weight Luffy can carry
    int n = sizeof(items) / sizeof(items[0]);

    // Create DP table
    int dp[n + 1][maxWeight + 1] = {0};

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in dp[n][maxWeight]
    cout << "Maximum value Luffy can carry: " << dp[n][maxWeight] << " Berries" << endl;

    return 0;
}
