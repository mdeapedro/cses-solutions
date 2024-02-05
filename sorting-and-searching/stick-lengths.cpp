#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    long long ans = 0;
    for (int i=0; i<n; i++) ans += abs(p[i]-p[n/2]);
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
