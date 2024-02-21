#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using indexed_set = __gnu_pbds::tree<int,
    __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;
    indexed_set a;
    for (int i = 1; i <= n; i++) a.insert(i);
    int pos = 0;
    while (!a.empty()) {
        pos = (pos+k)%n;
        auto it = a.find_by_order(pos);
        cout << *it << " ";
        a.erase(it);
        n--;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
