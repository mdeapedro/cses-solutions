#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long u, x;
        u = i*i;
        u *= u-1;
        u >>= 1;
        x = i-1;
        x *= x-1;
        x <<= 2;
        cout << u-x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}