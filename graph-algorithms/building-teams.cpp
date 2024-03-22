#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (vis[i] != 0) continue;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto xx : g[x]) {
                if (vis[xx] == 0) {
                    vis[xx] = vis[x] == 1 ? 2 : 1;
                    q.push(xx);
                } else if (vis[xx] == vis[x]) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
