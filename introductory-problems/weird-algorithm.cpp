#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    while (n > 1) {
        cout << n << ' ';
        if (n&1) n = n*3 + 1;
        else n >>= 1;
    }
    cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}