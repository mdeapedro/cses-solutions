#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long y, x;
    cin >> y >> x;
    if (y > x) {
        if (y&1) {
            y -= 1;
            y *= y;
            y += x;
        } else {
            y *= y;
            y -= x;
            y += 1;
        }
        cout << y << '\n';
    } else {
        if (x&1) {
            x *= x;
            x -= y;
            x += 1;
        } else {
            x -= 1;
            x *= x;
            x += y;
        }
        cout << x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}