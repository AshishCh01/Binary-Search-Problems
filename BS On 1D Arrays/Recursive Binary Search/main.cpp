
#include <vector>
#include <iostream>
using namespace std;
int bS(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;
    int mid = high + (high -low) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid]) return bS(nums, mid=1, high, target);
    return bS(nums, low, high - 1, target);
}
int findTarget (vector<int> nums, int target) {
    return bS(nums, 0, nums.size() - 1, target);
}
int main()
{
    vector<int> nums = {1,2,3,4,5};
    int target = 4;
    cout << findTarget(nums, target);

    return 0;
}