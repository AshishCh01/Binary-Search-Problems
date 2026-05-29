// returns index(7) ans = 8
#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 1;
    if (arr[n-1] > arr[n-2]) return n-1;
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = low +(high-low)/2;
        if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return mid;
        }
        else if (arr[mid] > arr[mid-1]) {
            low = mid+1;
        }
        else {
            if (arr[mid] > arr[mid=1]) {
                high = mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,5,1};
    cout << findPeakElement(arr);

    return 0;
}