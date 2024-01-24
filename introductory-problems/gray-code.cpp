#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, p[1<<16] {};
    cin >> n;
    string s(n+1, '0');
    s[n] = '\n';
    for (int k=2; k<(1<<n); k<<=1) {
        for (int i=k-1; i<(1<<n); i+=k) {
            p[i]++;
        }
    }
    for (int i=0; i<(1<<n); i++) {
        cout << s;
        s[n-1-p[i]] = s[n-1-p[i]] == '1' ? '0' : '1';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}