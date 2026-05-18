#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> res;
    vector<int> tmp;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) res.push_back(i);
            else {
                res.push_back(i);
                tmp.push_back(n/i);
            }
        }
    }
    while (!tmp.empty()) {
        res.push_back(tmp.back());
        tmp.pop_back();
    }
    return res;
}


void Solve(){
    // use case:
    vector<int> divisors = getDivisors(100);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}