#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<long long, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 1; i < n; i++) a[i][0] += a[i-1][0];
    for (int i = 0; i < n; i++) ans += a[i][1];
    for (int i = 0; i < n; i++) ans -= a[i][0];
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
