
#include <iostream>
using namespace std;
int mySqrt(int n) {
    int ans = 1;
    for (int i=0; i<=n; i++) {
        if ((long long)i*i <= n) {
            ans = i;
        }
        else {
            break;
        }
    }
    return ans;
}
int main()
{
    int n = 27;
    cout << mySqrt(n);
    return 0;
}