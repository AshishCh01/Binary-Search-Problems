
#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>>& matrix, int n, int m) {
    int idx = -1;
    int maxCount = -1;
    for (int i=0; i<n; i++) {
        int cntRow = 0;
        for (int j = 0; j<m; j++) {
            cntRow += matrix[i][j];
        }
        if (cntRow > maxCount) {
            maxCount = cntRow;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';

    return 0;
}