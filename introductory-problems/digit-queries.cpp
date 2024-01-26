#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, n, x = 9, i = 1;
    cin >> k;
    while (k - i*x > 0) {
        k -= i*x;
        x *= 10;
        i++;
    }
    k--;
    x /= 9;
    n = x+k/i;
    k = i-k%i;
    while (k-- > 1) n /= 10;
    cout << n%10 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) solve();
}
