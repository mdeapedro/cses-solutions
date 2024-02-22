#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using indexed_set = __gnu_pbds::tree<array<int, 2>,
    __gnu_pbds::null_type, less<array<int, 2>>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 5>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; i++) a[i][2] = i;
    sort(a.begin(), a.end(), [](auto a, auto b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
    indexed_set p;
    for (int i = 0; i < n; i++) {
        p.insert({-a[i][1], i});
        a[i][3] = p.order_of_key({-a[i][1], i});
    }
    p.clear();
    for (int i = n-1; i >= 0; i--) {
        p.insert({a[i][1], -i});
        a[i][4] = p.order_of_key({a[i][1], -i});
    }
    for (int i = n-2; i >= 0; i--) {
        if (a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1]) a[i][3] = a[i+1][3];
    }
    for (int i = 1; i < n; i++) {
        if (a[i][0] == a[i-1][0] && a[i][1] == a[i-1][1]) a[i][4] = a[i-1][4];
    }
    sort(a.begin(), a.end(), [](auto a, auto b){return a[2] < b[2];});
    for (auto x : a) cout << x[4] << " ";
    cout << "\n";
    for (auto x : a) cout << x[3] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
