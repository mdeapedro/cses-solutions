#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k, l = -1, r = ans;
        cin >> k;
        while (r - l > 1) {
            int m = (l + r)/2;
            if (k < a[m]) r = m;
            else          l = m;
        }
        if (r == ans) ans++;
        a[r] = k;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
