#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i][0];
        a[i][1] = i+1;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n-1;
    while (i < j) {
        if (a[i][0]+a[j][0] > x) j--;
        else if (a[i][0]+a[j][0] < x) i++;
        else {
            cout << a[i][1] << " " << a[j][1] << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
