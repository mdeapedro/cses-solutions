#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int K=6, M=1e9+7;
    int n;
    long long dp[K];
    fill(dp, dp+K, 1);
    cin >> n;
    for (int i=1; i<K; i++) {
        for (int j=0; j<i; j++) {
            dp[i] += dp[j];
        }
    }
    for (int i=K; i<n; i++) {
        for (int j=1; j<K; j++) {
            dp[i%K] += dp[(i+j)%K];
        }
        dp[i%K] %= M;
    }
    cout << dp[(n-1)%K] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
