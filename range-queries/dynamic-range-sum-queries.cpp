#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    vector<long long> segtree(4 * n + 1);
    auto build = [&](auto self, int v, int tl, int tr) -> void {
        if (tl == tr) {
            segtree[v] = x[tl];
        } else {
            int tm = (tl + tr) / 2;
            self(self, v * 2, tl, tm);
            self(self, v * 2 + 1, tm + 1, tr);
            segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
        }
    };
    auto query = [&](auto self, int v, int tl, int tr, int l, int r) -> long long {
        if (l > r) return 0;
        if (l == tl && r == tr) return segtree[v];
        int tm = (tl + tr) / 2;
        return self(self, v * 2, tl, tm, l, min(r, tm)) +
               self(self, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    };
    auto update = [&](auto self, int v, int tl, int tr, int pos, int value) -> void {
        if (tl == tr) segtree[v] = value;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) self(self, v * 2, tl, tm, pos, value);
            else self(self, v * 2 + 1, tm + 1, tr, pos, value);
            segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
        }
    };
    build(build, 1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            update(update, 1, 1, n, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(query, 1, 1, n, a, b) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
