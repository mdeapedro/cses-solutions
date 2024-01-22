#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x[200000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    sort(x, x+n);
    cout << unique(x, x+n)-x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
