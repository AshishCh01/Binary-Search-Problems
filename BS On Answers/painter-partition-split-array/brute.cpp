
#include <bits/stdc++.h>
using namespace std;
int countPainters(vector<int> &boards, int time) {
    int n = boards.size();
    int painters = 1; // Start with one painter
    long long boardsPainter = 0; // Current total board length assigned to a painter

    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            // If current board can be assigned to the same painter
            boardsPainter += boards[i];
        } else {
            // Otherwise, assign it to the next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

// Function to find the minimum time to paint all boards using at most k painters
int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end()); // Min possible time = largest board
    int high = accumulate(boards.begin(), boards.end(), 0); // Max time = total sum of boards

    for (int time = low; time <= high; time++) {
        if (countPainters(boards, time) <= k) {
            return time;
        }
    }
    return low;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}
