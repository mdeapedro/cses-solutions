#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int r = 1, ans = 1, n = s.size();
    for (int i=1; i<n; i++) {
        if (s[i] == s[i-1]) {
            r += 1;
        } else {
            ans = max(ans, r);
            r = 1;
        }
    }
    ans = max(ans, r);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}