
#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n -1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        // Calculate how many numbers are missing till vec[mid]
        int missing = arr[mid] - (mid + 1); // (mid+1) is the index after mid index means if mid index is 1 then (mid+1) is 2

        if (missing < k) {
            low = mid + 1;  // Move right to find more missing numbers
        } else {
            high = mid - 1; // Move left to find a smaller valid index
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> arr = {4, 7, 9, 10};  // (mid+1) = 2 -> missing = arr[mid] - (mid=1) = 7 - 2 = 5
    int k = 4;                     

    int ans = findKthPositive(arr, k); 

    cout << "The missing number is: " << ans << "\n";
    return 0;
}