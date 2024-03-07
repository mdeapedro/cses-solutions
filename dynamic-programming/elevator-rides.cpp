#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<array<int, 2>> dp(1<<n);
    dp[0][0] = 1;
    for (int i = 1; i < (1<<n); i++) {
        dp[i][0] = 1e9+1;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                auto p = dp[i ^ (1<<j)];
                if (p[1] + a[j] > x) {p[0]++; p[1] = a[j];}
                else p[1] += a[j];
                dp[i] = min(dp[i], p);
            }
        }
    }
    cout << dp[(1<<n)-1][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
