#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    list<int> a(n);
    iota(a.begin(), a.end(), 1);
    auto it = a.begin();
    while (!a.empty()) {
        if (it == a.end()) it = a.begin();
        it++;
        if (it == a.end()) it = a.begin();
        cout << *it << " ";
        it = a.erase(it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
