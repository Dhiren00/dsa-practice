#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if books can be allocated to m students
// such that maximum pages assigned <= mid
bool isPossible(vector<int>& books, int n, int m, int mid) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than mid
        if (books[i] > mid)
            return false;

        if (pages + books[i] <= mid) {
            pages += books[i];
        } else {
            students++;
            pages = books[i];

            if (students > m)
                return false;
        }
    }
    return true;
}

// Binary Search on Answer
int bookAllocation(vector<int>& books, int n, int m) {
    if (m > n) return -1;   // edge case

    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i];
        mx = max(mx, books[i]);
    }

    int st = mx, end = sum;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> books = {2, 1, 3, 4};
    int n = books.size();
    int m = 2;

    cout << bookAllocation(books, n, m);
    return 0;
}
