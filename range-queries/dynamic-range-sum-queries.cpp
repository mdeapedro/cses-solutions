#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        segtree.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    void update(int pos, int value) {
        update(1, 0, n - 1, pos, value);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

private:
    int n;
    vector<long long> segtree;

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) segtree[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return segtree[v];
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) segtree[v] = value;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, value);
            else update(v * 2 + 1, tm + 1, tr, pos, value);
            segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    auto segtree = SegmentTree(x);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            segtree.update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << segtree.query(a, b) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
