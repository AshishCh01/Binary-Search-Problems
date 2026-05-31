// k - number of bananas koko will eat (Le - 875)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int calculateTotalHours(vector<int>& piles, int hourly) {
    int totalHours = 0;
    for (int a : piles) {
        // Add hours using ceil
        // totalHours += ceil((double)(piles[i]) / (double)(hourly));
        totalHours += (a + hourly - 1) / hourly;
    }
    return totalHours;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int maxPile = *max_element(piles.begin(), piles.end());
    int low = 1; 
    int high = maxPile;
    int ans = maxPile;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int totalHours = calculateTotalHours(piles, mid);
        // If possible, try smaller speed
        if (totalHours <= h) {
            ans = mid;
            high = mid - 1;
        }
        // Otherwise, try larger speed
        else {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    // Hours allowed
    int h = 8;
    cout << minEatingSpeed(piles, h);

    return 0;
}