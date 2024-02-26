#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        m = max(m, a[i]);
        sum += a[i];
    }
    cout << max(2LL*m, sum) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
