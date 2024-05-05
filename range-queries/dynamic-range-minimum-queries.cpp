#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
using T = int;
public:
    SegmentTree(vector<T> &a) {
        n = a.size();
        vertices.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    inline void update(int i, int value) {
        update(1, 0, n - 1, i, value);
    }

    inline T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

private:
    vector<T> vertices;
    int n;

    inline int left(int v) { return v * 2; }
    inline int right(int v) { return v * 2 + 1; }
    inline T f(T a, T b) { return min(a, b); }
    const T NEUTRAL = 1e9;
    
    void build(vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) vertices[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, left(v), tl, tm);
            build(a, right(v), tm + 1, tr);
            vertices[v] = f(vertices[left(v)], vertices[right(v)]);
        }
    }

    void update(int v, int tl, int tr, int i, int value) {
        if (tl == tr) vertices[v] = value;
        else {
            int tm = (tl + tr) / 2;
            if (i <= tm) update(left(v), tl, tm, i, value);
            else update(right(v), tm + 1, tr, i, value);
            vertices[v] = f(vertices[left(v)], vertices[right(v)]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return NEUTRAL;
        if (l == tl && r == tr) return vertices[v];
        int tm = (tl + tr) / 2;
        return f(query(left(v), tl, tm, l, min(r, tm)),
                 query(right(v), tm + 1, tr, max(l, tm + 1), r));
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
