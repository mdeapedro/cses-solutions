#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, a[200000], b[200000];
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j] && a[i]+k < b[j]) i += 1;
        else if (a[i] > b[j] && a[i]-k > b[j]) j += 1;
        else {
            ans += 1;
            i += 1;
            j += 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}