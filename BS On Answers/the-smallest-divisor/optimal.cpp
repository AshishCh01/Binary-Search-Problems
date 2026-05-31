
#include<bits/stdc++.h>
using namespace std;
// Helper function to calculate sum of division results
int sumByD(vector<int>& arr, int div) {
    int sum = 0;
    for (int num : arr) {
        sum += ceil((double)num / div);
    }
    return sum;
}
int smallestDivisor(vector<int>& arr, int threshold) {
    if (arr.size() > threshold) return -1;

    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    // Binary search to find smallest divisor
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= threshold) {
            high = mid - 1;  // Try smaller divisor
        } else {
            low = mid + 1;   // Try larger divisor
        }
    }

    return low;
}

int main()
{
    
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    int ans = smallestDivisor(arr, threshold);
    cout << "The minimum divisor is: " << ans << "\n";

    return 0;
}