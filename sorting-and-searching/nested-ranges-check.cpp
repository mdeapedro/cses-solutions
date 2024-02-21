#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 5>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    if (n == 1) {
        cout << "0\n0\n";
        return;
    }
    for (int i = 0; i < n; i++) a[i][2] = i;
    sort(a.begin(), a.end(), [](auto a, auto b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
    int x = 0;
    if (a[0][0] == a[1][0] && a[0][1] == a[1][1]) x = a[0][1];
    for (int i = 0; i < n; i++) {
        if (a[i][1] <= x) a[i][3] = 1;
        else x = a[i][1];
    }
    x = 1e9+1;
    if (a[n-1][0] == a[n-2][0] && a[n-1][1] == a[n-2][1]) x = a[n-1][1];
    for (int i = n-1; i >= 0; i--) {
        if (a[i][1] >= x) a[i][4] = 1;
        else x = a[i][1];
    }
    sort(a.begin(), a.end(), [](auto a, auto b){return a[2] < b[2];});
    for (auto x : a) cout << x[4] << " ";
    cout << "\n";
    for (auto x : a) cout << x[3] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
