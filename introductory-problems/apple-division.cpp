#include <bits/stdc++.h>
using namespace std;
 
int n, p[20];
long long ans, sum = 0;
 
void search(int i, long long x) {
    if (i == n-1) ans = min(ans, abs(sum - (x<<1)));
    else {
        search(i+1, x+p[i]);
        search(i+1, x);
    }
}
 
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> p[i];
    for (int i=0; i<n; i++) sum += p[i];
    ans = sum;
    search(0, 0);
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
