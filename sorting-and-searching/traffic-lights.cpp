#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> s{0, x};
    multiset<int, greater<int>> ms {x};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = s.insert(p).first;
        ms.erase(ms.find(*next(it) - *prev(it)));
        ms.insert(p - *prev(it));
        ms.insert(*next(it) - p);
        cout << *ms.begin() << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
