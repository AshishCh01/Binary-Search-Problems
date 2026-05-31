
#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int>& nums, int threshold) {
    int n= nums.size();
    // Find the maximum element in the array
    int maxi = *max_element(nums.begin(), nums.end());
    // Try every possible divisor from 1 to maxi
    for (int d=1; d <= maxi; d++) {
        int sum = 0;
        // For each element, compute ceil(arr[i] / d) and add to sum
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(d));
        }
    
        // If the total sum is within the limit, return this divisor
        if (sum <= threshold) {
            return d;
        }
    }
    //  If no valid divisor is found, return -1
    return -1;
}
int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    int ans = smallestDivisor(nums, threshold);
    cout << "The minimum divisor is: " << ans << "\n";

    return 0;
}