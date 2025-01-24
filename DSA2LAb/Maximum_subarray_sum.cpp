// maximum subarray sum algorithm Divide and Conquer approach
#include <iostream>

using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    return max(max(maxSubArraySum(arr, low, mid), maxSubArraySum(arr, mid + 1, high)), maxCrossingSum(arr, low, mid, high));
}


int main() {
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum subarray sum is " << maxSum << endl;

    return 0;
}
//Output: Maximum subarray sum is 21
// Time complexity: O(nlogn)
// Space complexity: O(logn)



