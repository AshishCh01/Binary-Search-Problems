#include <bits/stdc++.h>
using namespace std;
// Function to check if we can place all cows with at least distance 'd'
bool canPlace(vector<int>& stalls, int k, int d) {
    // Place the first cow at the first stall
    int count = 1;
    int lastPos = stalls[0];

    // Try placing the remaining cows
    for (int i = 1; i < stalls.size(); i++) {
        // If current stall is at least 'd' away from last cow
        if (stalls[i] - lastPos >= d) {
            // Place a cow here
            count++;
            lastPos = stalls[i];
        }
        // If all cows placed successfully, return true
        if (count >= k) return true;
    }
    // Not possible to place all cows
    return false;
}
int maxDistance (vector<int> stalls, int k) {
    // Sort the stalls
    sort(stalls.begin(), stalls.end());

    // Define search space
    int low = 1;
    int high = stalls.back() - stalls.front();  // or stalls[n-1] - stalls[o]
    int ans = 0;

    // Apply binary search
    while (low <= high) {
        // Find mid distance
        int mid = low + (high - low) / 2;

        // If placing cows is possible with mid distance
        if (canPlace(stalls, k, mid) == true) {
            // Store this as potential answer
            ans = mid;
            // Try to find larger minimum distance
            low = mid + 1;
        }
        else {
            // Otherwise try smaller distance
            high = mid - 1;
        }
    }
    // Return the largest minimum distance
    return ans; // or high
}


int main()
{
   vector<int> stalls = {0,3,4,7,10,9};
    int k = 4;

    cout << maxDistance(stalls, k) << endl;

    return 0;
}