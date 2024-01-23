#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x = 0;
    cin >> n;
    for (int i=1; i<n; i++) {
        long long xi;
        cin >> xi;
        x += xi;
    }
    cout << n*(n+1)/2-x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}