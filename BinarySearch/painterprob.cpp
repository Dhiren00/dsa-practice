#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if boards can be painted with m painters
// such that max time taken by any painter <= mid
bool isPossible(vector<int>& boards, int n, int m, int mid) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is larger than mid, impossible
        if (boards[i] > mid)
            return false;

        if (time + boards[i] <= mid) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];

            if (painters > m)
                return false;
        }
    }
    return true;
}

// Painter's Partition using Binary Search
int paintersPartition(vector<int>& boards, int n, int m) {
    int sum = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        sum += boards[i];
        mx = max(mx, boards[i]);
    }

    int st = mx, end = sum;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isPossible(boards, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int n = boards.size();
    int m = 2;

    cout << paintersPartition(boards, n, m);
    return 0;
}
