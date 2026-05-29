#include <iostream>
#include <vector>
using namespace std;
pair<int,int> firstLastOccurrence(vector<int>& arr, int x) {

    int low = 0;
    int high = arr.size() - 1;

    int first = -1;
    int last = -1;

    // Find first occurrence
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    // Reset for last occurrence
    low = 0;
    high = arr.size() - 1;
    // Find last occurrence
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return {first, last};
}

int main() {
    vector<int> arr = {1,2,2,2,3,4,5};
    int x = 2;
    pair<int,int> ans =
        firstLastOccurrence(arr, x);

    cout << "First = "
         << ans.first << endl;

    cout << "Last = "
         << ans.second;
    return 0;
}