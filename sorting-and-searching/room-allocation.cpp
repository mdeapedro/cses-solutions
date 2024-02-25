#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; i++) a[i][2] = i;
    sort(a.begin(), a.end());
    multimap<int, int> m;
    a[0][3] = 1;
    int k = 1;
    for (int i = 1; i < n; i++) {
        m.insert({a[i-1][1], a[i-1][3]});
        auto it = m.lower_bound(a[i][0]);
        if (it == m.begin()) a[i][3] = ++k;
        else {
            a[i][3] = (*--it).second;
            m.erase(it);
        }
    }
    sort(a.begin(), a.end(), [](auto a, auto b) {return a[2] < b[2];});
    cout << k << "\n";
    for (auto x : a) cout << x[3] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
