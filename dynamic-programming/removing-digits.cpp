#include <bits/stdc++.h>
using namespace std;

int maxdig(int x) {
    return x < 10 ? x : max(x%10, maxdig(x/10));
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        n -= maxdig(n);
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
