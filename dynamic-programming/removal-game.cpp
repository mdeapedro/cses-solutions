#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> dp(n+1), p(n+1);
    for (int i = 1; i <= n; i++) cin >> dp[i];
    for (int i = 1; i <= n; i++) p[i] = dp[i] + p[i-1];
    for (int k = 1; k <= n-1; k++) {
        for (int i = 1; i <= n-k; i++) {
            dp[i] = p[i+k] - p[i-1] - min(dp[i], dp[i+1]);
        }
    }
    cout << dp[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
