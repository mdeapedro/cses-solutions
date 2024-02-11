#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }
    int ans = 1;
    for (int i=2; i<=n; i++) if (p[i] < p[i-1]) ans++;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
