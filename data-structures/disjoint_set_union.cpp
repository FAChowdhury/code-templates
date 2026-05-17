#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct DSU {
    std::vector<T> parent, size;

    DSU(T n) {
        parent.assign(n + 1, 0);
        size.assign(n + 1, 1);

        for (T i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    T find(T u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(T u, T v) {
        T pu = find(u);
        T pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            std::swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void Solve(){
    // use case:
    DSU<int> dsu(100005);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}