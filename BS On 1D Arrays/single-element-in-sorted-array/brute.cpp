
#include <iostream>
#include <vector>
using namespace std;
int singleElement(vector<int>& arr) {
    int n = arr.size();
    if (n == 1)
        return arr[0];
    for (int i = 0; i<n; i++) {
        // writing separately if and else if due to bounding error so we can't write directly else because at 
        // i = 0 → arr[i-1] becomes arr[-1] and i = n-1 → arr[i+1] becomes arr[n]
        if (i == 0) {               
            if (arr[i] != arr[i + 1])
                return arr[i];
        }

        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }

        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }
    return -1;
}

int main()
{
   vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};
   cout << singleElement(arr);

    return 0;
}