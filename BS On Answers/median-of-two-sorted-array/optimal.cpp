/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int ind2 = n / 2;   // represents index for odd length
    int ind1 = ind2 - 1;

    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (nums1[i] <= nums2[j]) {
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    while (i < n1) {
        if (cnt == ind1) ind1el = nums1[i];
        if (cnt == ind2) ind2el = nums1[i];
        cnt++;
        i++;
    }

    while (j < n2) {
        if (cnt == ind1) ind1el = nums2[j];
        if (cnt == ind2) ind2el = nums2[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1) {
        return ind2el;
    }

    return (ind1el + ind2el) / 2.0;
}
int main()
{
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {6,7,8,9};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}