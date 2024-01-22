#include <bits/stdc++.h>
using namespace std;

int n, x[200001];
vector<vector<int>> g;

int dfs(int v) {
    x[v] = 0;
    for (auto vv : g[v]) {
        x[v] += dfs(vv)+1;
    }
    return x[v];
}

void solve() {
    cin >> n;
    g.assign(n+1, vector<int>());
    for (int i=2; i<=n; i++) {
        int ei;
        cin >> ei;
        g[ei].push_back(i);
    }
    cout << dfs(1);
    for (int i=2; i<=n; i++) {
        cout << ' ' << x[i];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
