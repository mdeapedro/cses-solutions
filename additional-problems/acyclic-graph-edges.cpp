#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> vis(n);
    auto dfs = [&](auto dfs, int node, int parent) -> void {
        vis[node] = true;
        for (int adj : g[node]) {
            if (!vis[adj]) {
                cout << adj + 1 << " " << node + 1 << "\n";
            }
        }
        for (int adj : g[node]) {
            if (!vis[adj]) {
                dfs(dfs, adj, node);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i, -1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
