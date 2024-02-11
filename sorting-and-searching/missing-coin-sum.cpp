#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    long long ans = 0;
    for (int i=0; i<n; i++) {
        if (x[i] > ans+1) break;
        else ans += x[i];
    }
    cout << ans+1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
