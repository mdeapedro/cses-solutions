#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x[200000];
    cin >> n;
    for (int i=0; i<n; i++) cin >> x[i];
    long long ans = 0;
    for (int i=1; i<n; i++) {
        if (x[i] < x[i-1]) {
            ans += x[i-1] - x[i];
            x[i] = x[i-1];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}