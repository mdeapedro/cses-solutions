#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
void solve() {
    cin >> n >> m;
    multiset<int> t;
    for (int i=0; i<n; i++) {
        int ti;
        cin >> ti;
        t.insert(ti);
    }
    for (int i=0; i<m; i++) {
        int hi;
        cin >> hi;
        auto x = t.upper_bound(hi);
        if (x == t.begin()) cout << "-1\n";
        else {
            x--;
            cout << *x << "\n";
            t.erase(x);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
