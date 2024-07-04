#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<bool> vis(n);
    int node = 0;
    int dist = 0;
    auto dfs = [&](auto dfs, int cur_node, int cur_dist) -> void {
        if (dist < cur_dist) {
            node = cur_node;
            dist = cur_dist;
        }
        vis[cur_node] = true;
        for (int adj : tree[cur_node]) {
            if (vis[adj]) continue;
            dfs(dfs, adj, cur_dist + 1);
        }
    };
    dfs(dfs, node, 0);
    vis.assign(n, false);
    dfs(dfs, node, 0);
    cout << dist << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
