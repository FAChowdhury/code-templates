#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// Return a list of the rolling hash of every subarray of size k in nums
// Assumes that nums[i] is non-negative.
vector<ull> rollingHash(vector<int> nums, int k) {
    ull BASE = 1e6+3; // update this so that it is an odd prime number roughly >= to the number of unique characters in input array
    ull P = (1ULL<<31) - 1;
    vector<ull> res;
    ull pow = 1;
    for (int i = 1; i < k; ++i) pow = (pow * BASE) % P; 
    ull hash = 0;
    for (int i = 0; i < k; ++i) hash = (hash * BASE + ((ull)nums[i] + P)) % P; 
    res.push_back(hash); 
    for (int i = k; i < nums.size(); ++i) { 
        ull remove = (((ull)nums[i - k] + P) * pow) % P;
        hash = (hash + P - remove) % P;
        hash = (hash * BASE) % P;
        hash = (hash + (ull)nums[i] + P) % P;
        res.push_back(hash);
    }
    return res;
}

void Solve(){
    // use case:
    vector<int> nums({34, 354, 12, 76, 12324, 12 , 3546});
    auto hash3 = rollingHash(nums, 3);
    for (const auto& hash : hash3) cout << hash << endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}