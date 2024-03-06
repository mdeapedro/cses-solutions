#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int M = 1e9+7;
    int n;
    cin >> n;
    if (n%4 == 1 || n%4 == 2) {
        cout << "0\n";
        return;
    }
    int sum = (n*(n+1))/4;
    vector<int> dp(sum+1);
    dp[0] = 1;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        k = min(k+i, sum);
        for (int j = k; j >= i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= M;
        }
    }
    int p = M-2;
    long long x = 2, r = 1;
    while (p > 0) {
        if (p&1) {
            r *= x;
            r %= M;
        }
        x *= x;
        x %= M;
        p >>= 1;
    }
    r *= dp[sum];
    r %= M;
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
