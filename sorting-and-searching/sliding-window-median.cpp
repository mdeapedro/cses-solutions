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
    int k0 = (k-1)/2;
    auto mid = [&](){ return (*s.find_by_order(k0))[0]; };
    cout << mid();
    for (int i = k; i < n; i++) {
        s.erase({ a[i-k], i-k });
        s.insert({ a[i], i });
        cout << " " << mid();
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
