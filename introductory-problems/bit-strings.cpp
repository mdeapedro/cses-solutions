#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int M = 1e9+7;
    int n;
    cin >> n;
    long long r = 1, a = 2;
    while (n > 0) {
        if (n&1) {
            r *= a;
            r %= M;
        }
        a *= a;
        a %= M;
        n >>= 1;
    }
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}