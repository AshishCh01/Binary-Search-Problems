#include <iostream>
#include <vector>
using namespace std;

pair<int,int> floorCeil(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size()-1;

    int floorVal = -1;
    int ceilVal = -1;

    while(low <= high) {

        int mid = low + (high-low)/2;

        if(arr[mid] == target) {
            floorVal = arr[mid];
            ceilVal = arr[mid];
            return {floorVal, ceilVal};
        }

        else if(arr[mid] < target) {
            floorVal = arr[mid];
            low = mid + 1;
        }

        else {
            ceilVal = arr[mid];
            high = mid - 1;
        }
    }

    return {floorVal, ceilVal};
}

int main() {

    vector<int> arr = {1,3,5,7,9};

    int target = 6;

    pair<int,int> ans =
        floorCeil(arr,target);

    cout << "Floor = "
         << ans.first << endl;

    cout << "Ceil = "
         << ans.second;
}