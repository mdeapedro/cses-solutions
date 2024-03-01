#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int M = 1e9+7;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<long long>> dp(n, vector<long long>(m+2));
    if (a[0]) dp[0][a[0]] = 1;
    else for (int i = 1; i <= m; i++) dp[0][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = -1; k < 2; k++) dp[i][j] += dp[i-1][j+k];
            dp[i][j] %= M;
        }
        if (a[i] > 0) {
            long long x = dp[i][a[i]];
            for (int j = 1; j <= m; j++) dp[i][j] = 0;
            dp[i][a[i]] = x;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + dp[n-1][i])%M;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
