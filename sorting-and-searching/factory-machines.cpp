#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = 0, r = 1e18+1;
    while (r - l > 1) {
        long long m = (r + l)/2, x = 0;
        for (auto ai : a) x += min(m/ai, (long long)1e9);
        if (t <= x) r = m;
        else        l = m;
    }
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
