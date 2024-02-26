#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long sum = a[0];
    int l = 0, r = 1, ans = 0;
    while (r <= n) {
        if (sum <= x) {
            if (sum == x) ans++;
            sum += a[r++];
        } else sum -= a[l++];
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
