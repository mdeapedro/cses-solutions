#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), r(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int j = i-1;
        while (a[j] >= a[i]) j = r[j];
        r[i] = j;
    }
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
