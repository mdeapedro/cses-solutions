#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        --a; --b;
        g[a].push_back({ b, x });
    }

    vector<long long> dist(n, -1e18);
    dist[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int a = 0; a < n; ++a) {
            for (auto [b, x] : g[a]) {
                if (dist[b] < dist[a] + x) {
                    dist[b] = dist[a] + x;
                }
            }
        }
    }
    vector<int> improve(n);
    vector<bool> vis(n);
    for (int a = 0; a < n; ++a) {
        for (auto [b, x] : g[a]) {
            if (dist[b] < dist[a] + x) {
                improve[b] = 1;
            }
        }
    }
    auto dfs = [&](auto dfs, int a) -> void {
        if (vis[a]) return;
        vis[a] = true;
        if (improve[a] == 1) improve[a] = 2;
        for (auto [b, x] : g[a]) {
            dfs(dfs, b);
        }
    };
    dfs(dfs, 0);
    vis.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (vis[i] || improve[i] != 2) continue;
        dfs(dfs, i);
    }

    if (vis[n - 1]) cout << "-1\n";
    else cout << dist[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
