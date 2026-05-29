#include <iostream>
#include <vector>
using namespace std;
int searchTarget (vector<int> arr, int target) {
    int n = arr.size();
    int low = 0; 
    int high = n-1;
    while (low <= high) {   // Base condition
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (target > arr[mid]) {
            low = mid+1;
        }
        else {
            high = mid-1;   // target < arr[mid]
        }
    }
    return -1;  // if low >= high
}
int main() {
    vector<int> arr = {1,2,3,4};
    int target = 4;
    cout << searchTarget(arr, target);
}