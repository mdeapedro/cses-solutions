#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int M = 1e9+7;
    int n, x;
    cin >> n >> x;
    vector<int> c(n), dp(x+1);
    for (int i = 0; i < n; i++) cin >> c[i];
    dp[0] = 1;
    for (auto ci : c) for (int k = 1; k <= x; k++) if (k - ci >= 0) {
        dp[k] += dp[k - ci];
        dp[k] %= M;
    }
    cout << dp[x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
