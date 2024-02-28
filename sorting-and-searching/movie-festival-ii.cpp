#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][1] >> a[i][0];
    sort(a.begin(), a.end());
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(a[i][1]);
        if (it == s.begin()) {
            if ((int)s.size() < k) {
                s.insert(a[i][0]);
                ans++;
            }
        } else {
            s.erase(--it);
            s.insert(a[i][0]);
            ans++;
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
