#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long x = 2;
    int n2 = 0, n5 = 0;
    while (x <= n) {
        n2 += n/x;
        x <<= 1;
    }
    x = 5;
    while (x <= n) {
        n5 += n/x;
        x *= 5;
    }
    cout << min(n2, n5) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}