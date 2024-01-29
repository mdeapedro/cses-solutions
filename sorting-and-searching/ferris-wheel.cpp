#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;
int n, x, p[MAX_N];

void solve() {
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> p[i];
    sort(p, p+n);
    int i=0, j=n-1, ans=0;
    while (i <= j) {
        if (p[i]+p[j] <= x) i++;
        j--;
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
