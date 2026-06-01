#include <bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int>& arr, int m) {
    int n = arr.size();
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = findPages(arr, m);
    cout << "The answer is: " << ans << "\n";

    return 0;
}