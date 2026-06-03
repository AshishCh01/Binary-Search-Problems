#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    
    if (n % 2 == 1) {
        return arr[n / 2];
    }
    
    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout << findMedian(arr);

    return 0;
}