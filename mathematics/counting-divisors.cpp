#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    const int MAX_X = 1e6;
    vector<int> d(MAX_X+1, 2);
    d[1] = 1;
    for (int i = 2; i <= MAX_X/2; i++) {
        for (int j = 2*i; j <= MAX_X; j += i) {
            d[j]++;
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << d[x] << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
