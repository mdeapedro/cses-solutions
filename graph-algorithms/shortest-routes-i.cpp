#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long, int>>> g(n, vector<pair<long long, int>>());
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({c, b});
    }
    vector<long long> ans(n, -1);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        long long c = -pq.top().first;
        int a = pq.top().second;
        pq.pop();
        if (ans[a] > -1) continue;
        ans[a] = c;
        for (auto cb : g[a]) {
            pq.push({-c-cb.first, cb.second});
        }
    }
    for (int a = 0; a < n; a++) cout << ans[a] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
