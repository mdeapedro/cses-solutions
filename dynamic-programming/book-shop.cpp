#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++) {
        for (int j = x - h[i]; j >= 0; j--) {
            dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
        }
    }
    cout << dp[x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
