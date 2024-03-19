#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> vis;
vector<vector<int>> g;

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    for (auto xx : g[x]) {
        dfs(xx);
    }
}

void solve() {
    cin >> n >> m;
    vis.resize(n + 1);
    g.resize(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int k = 0;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            k++;
            g[0].push_back(i);
            dfs(i);
        }
    }
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << "1 " << g[0][i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
