#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];
    map<int, int> m;
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (m.count(k[i]) && i - m[k[i]] < cur + 1) cur = i - m[k[i]];
        else cur++;
        m[k[i]] = i;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
