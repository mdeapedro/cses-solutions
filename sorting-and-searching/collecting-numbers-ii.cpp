#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n+2), p(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        p[x[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) if (p[i+1] < p[i]) ans++;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (x[a] > x[b]) swap(a, b);
        if (x[a] + 1 == x[b]) {
            if (a > b) ans--;
            else       ans++;
        } else {
            if (p[x[a]+1] < a) ans--;
            if (p[x[a]+1] < b) ans++;
            if (b < p[x[b]-1]) ans--;
            if (a < p[x[b]-1]) ans++;
        }
        if (a < p[x[a]-1]) ans--;
        if (b < p[x[a]-1]) ans++;
        if (p[x[b]+1] < b) ans--;
        if (p[x[b]+1] < a) ans++;
        cout << ans << "\n";
        swap(p[x[a]], p[x[b]]);
        swap(x[a], x[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
