#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lowerBound(vector<int>& arr, int target) { // return the index not the value
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

// OR using STL
int main() {
    vector<int> arr = {1,2,2,2,3,4,5};

    int target = 2;

    int lb = lower_bound(
        arr.begin(),
        arr.end(),
        target
    ) - arr.begin();

    int ub = upper_bound(
        arr.begin(),
        arr.end(),
        target
    ) - arr.begin();

    cout << lb << endl;
    cout << ub;
}