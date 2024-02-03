#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> ab(n);
    priority_queue<int, vector<int>, greater<int>> b;
    for (int i=0; i<n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        ab[i] = {ai, bi};
    }
    sort(ab.begin(), ab.end());
    int ans = 0;
    for (int i=0; i<n; i++) {
        b.push(ab[i][1]);
        while (b.top() < ab[i][0]) b.pop();
        ans = max(ans, (int)b.size());
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
