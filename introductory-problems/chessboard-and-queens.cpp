#include <bits/stdc++.h>
using namespace std;

const int K = 8;
bool cb[K][K], d1[2*K], d2[2*K], col[K];
int ans;

void rec(int i) {
    if (i == K) ans++;
    else for (int j=0; j<K; j++) {
        if (cb[i][j] || d1[i+j] || d2[i-j+K] || col[j]) continue;
        col[j] = d1[i+j] = d2[i-j+K] = true;
        rec(i+1);
        col[j] = d1[i+j] = d2[i-j+K] = false;
    }
}

void solve() {
    for (int i=0; i<K; i++) {
        for (int j=0; j<K; j++) {
            char c;
            cin >> c;
            cb[i][j] = c == '*';
        }
    }
    rec(0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
