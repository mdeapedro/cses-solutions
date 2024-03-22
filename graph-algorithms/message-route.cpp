#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1, -1);
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto xx : g[x]) {
            if (vis[xx] == -1) {
                vis[xx] = x;
                q.push(xx);
            }
        }
    }
    if (vis[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    stack<int> s;
    int x = n;
    while (vis[x] >= 0) {
        s.push(x);
        x = vis[x];
    }
    cout << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
