#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    vector<vector<int>> dp(a, vector<int>(b));
    for (int j = 1; j < b; j++) dp[0][j] = j;
    for (int i = 1; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (i >= j) dp[i][j] = dp[j][i];
            else {
                dp[i][j] = 1e9;
                for (int k = 1; k <= (j+1)/2; k++) dp[i][j] = min(dp[i][j], 1 + dp[i][j-k] + dp[i][k-1]);
                for (int k = 1; k <= (i+1)/2; k++) dp[i][j] = min(dp[i][j], 1 + dp[i-k][j] + dp[k-1][j]);
            }
        }
    }
    cout << dp[a-1][b-1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
