#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    long long ans, x, sum;
    cin >> n >> sum;
    ans = sum;
    for (int i=1; i<n; i++) {
        cin >> x;
        sum = sum < 0 ? x : sum + x;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
