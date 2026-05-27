#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& arr, int target) {
    int n = arr.size(); 
    int low = 0; 
    int high = n-1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[low] <= arr[mid]) { // left sorted
            if (arr[low] <= target && target <= arr[mid]) {
                high = mid-1;
            }
            else {  // or right sorted
                low = mid+1;
            }
        }
        else {  
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {7,8,9,1,2,3,4,5};
    int target = 1;
    cout << search(arr, target);
    return 0;
}