#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int K = 25;
    int n, q;
    cin >> n >> q;
    vector<vector<int>> st(K + 1, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> st[0][i];
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int i = __bit_width(b - a + 1) - 1;
        cout << min(st[i][a], st[i][b - (1 << i) + 1]) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
