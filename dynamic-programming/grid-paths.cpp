#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    const int M = 1e9+7;
    int n;
    cin >> n;
    vector<string> g(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        if (g[i][0] == '.') dp[i][0] = 1;
        else break;
    }
    for (int j = 0; j < n; j++) {
        if (g[0][j] == '.') dp[0][j] = 1;
        else break;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (g[i][j] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
            else dp[i][j] = 0;
        }
    }
    cout << dp[n-1][n-1] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
