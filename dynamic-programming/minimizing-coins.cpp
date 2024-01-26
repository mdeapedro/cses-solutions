#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n), dp(x+1, 1e9);
    dp[0] = 0;
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=1; i<=x; i++) for (auto ci:c) if (i-ci >= 0) dp[i] = min(dp[i], dp[i-ci]+1);
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
