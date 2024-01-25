#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int q = 1, r = 1;
    for (int i=1; i<(int)s.size(); i++) {
        q *= i+1;
        if (s[i] == s[i-1]) q /= ++r;
        else r = 1;
    }
    cout << q << '\n';
    do cout << s << '\n';
    while (next_permutation(s.begin(), s.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}