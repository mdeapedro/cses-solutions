#include <bits/stdc++.h>
using namespace std;

int n, m;
char x[1000][1000];

int dfs(int i, int j) {
    if (i>=0 && i<n && j>=0 && j<m && x[i][j]=='.') {
        x[i][j] = '#';
        dfs(i, j+1);
        dfs(i+1, j);
        dfs(i, j-1);
        dfs(i-1, j);
        return 1;
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans += dfs(i, j);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
