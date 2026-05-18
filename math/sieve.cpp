#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<char> prime(n + 1, 1);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == 1) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]) res.push_back(p);
    }
    return res;
}

void Solve(){
    // use case:
    vector<int> primes = sieve(35);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}