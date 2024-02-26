#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0];
    for (int i = 0; i < n; i++) a[i][1] = i;
    sort(a.begin(), a.end());
    for (int i = 0; i < n-2; i++) {
        for (int j = n-1; j > i; j--) {
            int k = x - a[i][0] - a[j][0];
            if      (k > a[j][0]) break;
            else if (k < a[i][0]) continue;
            int l = i, r = j;
            while (r - l > 1) {
                int m = (r + l)/2;
                if (k <= a[m][0]) r = m;
                else              l = m;
            }
            if (r != j && a[r][0] == k) {
                cout << a[i][1] + 1 << " "
                     << a[r][1] + 1 << " "
                     << a[j][1] + 1 << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
