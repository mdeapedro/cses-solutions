#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<long long, int> m;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        m[sum]++;
    }
    long long ans = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        ans += m[x];
        x += a[i];
        sum += a[i];
        m[sum]--;
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
