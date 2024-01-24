#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n&1) {
        n += 1;
        if (n%4 != 0) {
            cout << "NO\n";
            return;
        }
        int a = n>>2, b = n>>1, c = a+b;
        cout << "YES\n" << b-1 << '\n';
        for (int i=1; i<a; i++) cout << i << ' ';
        for (int i=c; i<n; i++) cout << i << ' ';
        cout << '\n' << b << '\n';
        for (int i=a; i<c; i++) cout << i << ' ';
        cout << '\n';
    } else {
        if (n%4 != 0) {
            cout << "NO\n";
            return;
        }
        int a = (n>>2)+1, b = n>>1, c=a+b;
        cout << "YES\n" << b << '\n';
        for (int i=1; i<a; i++) cout << i << ' ';
        for (int i=c; i<=n; i++) cout << i << ' ';
        cout << '\n' << b << '\n';
        for (int i=a; i<c; i++) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}