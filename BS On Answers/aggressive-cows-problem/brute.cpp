#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    // Step 2: Get the maximum possible distance
    int maxDist = stalls[n - 1] - stalls[0];

    // Step 3: Variable to store answer
    int ans = 0;
    
    for (int d=0; d<maxDist; d++) {
        if (canPlace(stalls, k, d) == true) {
            ans = d;
        }
    }
    return ans;
}
int main()
{
    vector<int> stalls = {0,3,4,7,10,9};
    int k = 4;
    cout << maxDistance(stalls, k) << endl;
    return 0;
}