#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using indexed_set = __gnu_pbds::tree<array<int, 2>,
    __gnu_pbds::null_type, less<array<int, 2>>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    indexed_set s;
    for (int i = 0; i < k; i++) s.insert({ a[i], i });
    int m = (*s.find_by_order(k/2))[0];
    long long ans = 0;
    for (int i = 0; i < k; i++) ans += abs(a[i]-m);
    cout << ans;
    if (k&1) {
        for (int i = k; i < n; i++) {
            ans += abs(a[i]-m);
            s.insert({ a[i], i });
            if ((int)s.order_of_key({ a[i-k], i-k }) <= k/2) {
                m = (*s.find_by_order(k/2+1))[0];
            } else {
                m = (*s.find_by_order(k/2))[0];
            }
            ans -= abs(a[i-k]-m);
            s.erase({ a[i-k], i-k });
            cout << " " << ans;
        }
    } else {
        for (int i = k; i < n; i++) {
            if ((int)s.order_of_key({ a[i-k], i-k }) < k/2) {
                m = (*s.find_by_order(k/2))[0];
            } else {
                m = (*s.find_by_order(k/2-1))[0];
            }
            ans -= abs(a[i-k]-m);
            s.erase({ a[i-k], i-k });
            ans += abs(a[i]-m);
            s.insert({ a[i], i });
            cout << " " << ans;
        }
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
