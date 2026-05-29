
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int findMin(vector<int>& nums) {

    // Initialize answer with a large number
    int minVal = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {

        // Update minimum value
        minVal = min(minVal, nums[i]);
    }
    return minVal;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = findMin(nums);
    cout << "Minimum element is " << result << endl;
    return 0;
}