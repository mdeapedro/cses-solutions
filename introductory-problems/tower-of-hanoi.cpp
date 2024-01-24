#include <bits/stdc++.h>
using namespace std;

void dp(int n, int a, int b) {
    if (n == 1) cout << a << ' ' << b << '\n';
    else {
        int c = 6-a-b;
        dp(n-1, a, c);
        dp(1, a, b);
        dp(n-1, c, b);
    }
}

void solve() {
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n';
    dp(n, 1, 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}