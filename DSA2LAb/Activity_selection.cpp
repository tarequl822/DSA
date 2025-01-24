#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

// Comparator function to sort activities by their finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity activities[], int n) {
    // Sort activities by finish time
    sort(activities, activities + n, compare);

    cout << "Selected activities: ";

    // The first activity is always selected
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << "), ";

    // Iterate through the activities
    for (int j = 1; j < n; j++) {
        // If the current activity starts after or when the previous activity finishes
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << "), ";
            i = j;
        }
    }
}

int main() {
    // Array of activities
    Activity activities[] = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, 
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
