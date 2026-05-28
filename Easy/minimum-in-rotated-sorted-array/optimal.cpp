
#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1; 
    int ans = INT_MAX;
    while (low <= high) {
       int mid = low + (high - low) / 2;
       if (nums[low] <= nums[mid]) {    // if left half is sorted -> pick smallest element from left half
           ans = min(ans, nums[low]);
           low = mid + 1;
       }
       else {   // else right half is sorted ->pick smallest element from right half
           high = mid - 1;
           ans = min(ans, nums[mid]);
       }
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = findMin(nums);
    cout << "Minimum element is " << result << endl;
    return 0;
}