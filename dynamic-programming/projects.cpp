#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> p[i];
    }
    vector<array<int, 3>> x(2*n+1);
    for (int i = 1; i <= n; i++) x[i] = {a[i], 0, i};
    for (int i = 1; i <= n; i++) x[i+n] = {b[i], 1, i};
    sort(x.begin(), x.end());
    vector<long long> dp(2*n+1);
    for (int i = 1; i <= 2*n; i++) {
        if (x[i][1] == 0) dp[i] = dp[i-1];
        else {
            int l = -1, r = i;
            while (r - l > 1) {
                int m = (l + r)/2;
                if (a[x[i][2]] <= x[m][0]) r = m;
                else                       l = m;
            }
            dp[i] = max(dp[i-1], dp[r-1] + p[x[i][2]]);
        }
    }
    cout << dp[2*n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
