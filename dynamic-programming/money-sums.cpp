#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    vector<bool> dp(sum+1);
    dp[0] = true;
    for (auto x : a) {
        for (int i = sum; i >= x ; i--) {
            if (dp[i - x]) dp[i] = true;
        }
    }
    int m = 0;
    for (int i = 1; i <= sum; i++) if (dp[i]) m++;
    cout << m << "\n";
    for (int i = 1; i <= sum; i++) if (dp[i]) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
