// k - number of bananas koko will eat (Le - 875)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// Function to calculate total hours for given speed
int calculateTotalHours(vector<int>& piles, int hourly) {
    int totalHours = 0;
    for (int a : piles) {
        // Add hours using ceil
        totalHours += (a + hourly - 1) / hourly;
    }
    return totalHours;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int maxPiles = *max_element(piles.begin(), piles.end());
    int k = 0;
    for (int i = 1; i <= maxPiles; i++) {
        int hours = calculateTotalHours(piles, i);

        // If hours fit within h
        if (hours <= h) {
            return i;
        }
    }
    return maxPiles;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    // Hours allowed
    int h = 8;
    cout << minEatingSpeed(piles, h);

    return 0;
}