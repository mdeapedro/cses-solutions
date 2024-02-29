#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n+1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) x[i] += x[i-1];
    multiset<long long> s;
    long long ans = x[a];
    for (int i = a; i < b; i++) {
        s.insert(x[i-a]);
        ans = max(ans, x[i] - *s.begin());
    }
    for (int i = b; i <= n; i++) {
        s.insert(x[i-a]);
        ans = max(ans, x[i] - *s.begin());
        s.erase(s.find(x[i-b]));
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
