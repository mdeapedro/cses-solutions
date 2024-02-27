#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m;
    long long ans = 0;
    int i = 0, j = 0;
    while (j < n) {
        m[a[j]]++;
        if ((int)(m.size()) <= k) {
            ans += j - i + 1;
            j++;
        } else {
            while ((int)(m.size()) > k) {
                m[a[i]]--;
                if (m[a[i]] == 0) m.erase(a[i]);
                i++;
            }
            m[a[j]]--;
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
