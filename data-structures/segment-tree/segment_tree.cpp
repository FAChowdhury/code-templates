#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> t;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        t.resize(2*n);
        std::copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = std::max(t[i<<1], t[i<<1|1]); // *
    }

    void modify(int p, int value) {
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = std::max(t[p], t[p^1]); // *
    }

    int query(int l, int r) { 
        int res = -1;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l&1) res = std::max(res, t[l++]); // *
            if (!(r&1)) res = std::max(res, t[r--]); // *
        }
        return res;
    }
};

void Solve() {
    // use case:
    vector<int> nums({1, 2, 3, 4, 5});
    SegmentTree sTree(nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}