#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), r(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += a[i];
        k %= n;
        k += n;
        k %= n;
        r[k]++;
    }
    k = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += r[k];
        k += a[i];
        k %= n;
        k += n;
        k %= n;
        r[k]--;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
