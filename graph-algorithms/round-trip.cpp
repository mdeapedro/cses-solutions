#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> par(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int u = 0;
    par[1] = -1;
    auto dfs = [&](auto self, int x) -> void {
        for (auto y : g[x]) {
            if (u > 0) return;
            if (y == par[x]) continue;
            if (par[y] == 0) {
                par[y] = x;
                self(self, y);
            } else {
                par[y] = x;
                u = y;
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (par[i] <= 0) {
            dfs(dfs, i);
            if (u > 0) break;
        }
    }
    if (u == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int v = u;
    stack<int> s;
    do {
        s.push(v);
        v = par[v];
    } while (v != u);
    cout << s.size() + 1 << "\n" << v;
    while (!s.empty()) {
        cout << " " << s.top();
        s.pop();
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
