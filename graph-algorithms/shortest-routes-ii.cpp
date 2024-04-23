#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    const long long INF = 1e18;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = dist[a][b];
    }
    for (int a = 0; a < n; a++) dist[a][a] = 0;
    for (int k = 0; k < n; k++) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
