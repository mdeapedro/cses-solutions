#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({b, a});
    }
    int ans = 0, b = -1;
    while (!pq.empty()) {
        if (pq.top()[1] >= b) {
            ans++;
            b = pq.top()[0];
        }
        pq.pop();
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
