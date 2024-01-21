#include <bits/stdc++.h>
using namespace std;

int n, m;
char x[1000][1000];

bool f(int i, int j) {
    if (i>=0 && i<n && j>=0 && j<m && x[i][j]=='.') {
        x[i][j] = '#';
        f(i, j+1);
        f(i+1, j);
        f(i, j-1);
        f(i-1, j);
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans += f(i, j);
        }
    }
    cout << ans << '\n';
}
