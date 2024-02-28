#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = -1, r = n*1e9+1;
    while (r - l > 1) {
        long long m = (r + l)/2, sum = 0;
        int t = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > m) {
                t = k+1;
                break;
            }
            if (sum + a[i] > m) {
                t++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }
        if (t > k) l = m;
        else       r = m;
    }
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
