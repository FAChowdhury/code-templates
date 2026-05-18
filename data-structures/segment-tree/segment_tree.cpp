#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
public:
    vector<int> t;
    int n;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        t.resize(2*n);
        std::copy(nums.begin(), nums.end(), t.begin() + n);
        for (int i = n-1; i > 0; --i) t[i] = t[2*i] + t[2*i + 1];
    }
    
    void update(int index, int val) {
        index += n;
        t[index] = val;
        while (index > 1) {
            index /= 2;
            t[index] = t[2*index] + t[2*index + 1];
        }
    }
    
    int sumRange(int left, int right) {
        left += n; right += n;
        int sum = 0;
        while (left <= right) {
            if (left&1) sum += t[left++];
            if (right%2==0) sum += t[right--];
            left/=2;
            right/=2;
        }
        return sum;
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