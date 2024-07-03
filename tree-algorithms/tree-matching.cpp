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
    vector<bool> taken(n);
    int ans = 0;
    auto dfs = [&](auto dfs, int node, int parent) -> void {
        for (int adj : tree[node]) {
            if (adj == parent) continue;
            dfs(dfs, adj, node);
        }
        if (parent != -1 && !taken[node] && !taken[parent]) {
            ans++;
            taken[node] = true;
            taken[parent] = true;
        }
    };
    dfs(dfs, 0, -1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
