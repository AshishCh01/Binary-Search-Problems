// find the floor
#include <iostream>
using namespace std;
int mySqrt(int n) {
    int low = 1;
    int high = n;
    int ans = 1;
    while (low <= high) {
        int mid = (low + high)/2;
        if ((mid * mid) <= n) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid -1;
        }
    }
    return ans; // return ans or high
}
int main()
{
    int n = 27;
    cout << mySqrt(n);
    return 0;
}