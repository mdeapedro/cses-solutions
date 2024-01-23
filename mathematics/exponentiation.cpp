#include <bits/stdc++.h>
using namespace std;

int pwr(long long a, int b, int M) {
    long long r = 1;
    while (b > 0) {
        if (b&1) {
            r *= a;
            r %= M;
        }
        a *= a;
        a %= M;
        b >>= 1;
    }
    return r%M;
}

void solve() {
    const int M = 1e9+7;
    int a, b;
    cin >> a >> b;
    cout << pwr(a, b, M) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) solve();
}