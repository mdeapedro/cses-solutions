#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) x[i] += x[i - 1];
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << x[b] - x[a - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
