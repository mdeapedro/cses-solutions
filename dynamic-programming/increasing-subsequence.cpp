#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        int x, l = -1, r = k;
        cin >> x;
        while (r - l > 1) {
            int m = (r + l)/2;
            if (x <= a[m]) r = m;
            else           l = m;
        }
        a[r] = x;
        if (r == k) k++;
    }
    cout << k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
