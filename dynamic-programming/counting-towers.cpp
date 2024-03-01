#include <bits/stdc++.h>
using namespace std;


void solve() {
    const int MAX_N = 1e6;
    const int M = 1e9+7;
    vector<array<long long, 2>> dp(MAX_N+1);
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % M;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % M;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % M << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
