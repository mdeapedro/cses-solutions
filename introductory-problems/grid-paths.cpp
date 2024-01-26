#include <bits/stdc++.h>
using namespace std;

const int K = 7;
string p;
int g[K][K], ans;
bool vis[K][K];

void dfs(int i, int j, int k, char prev) {
    if (i < 0 || i >= K || j < 0 || j >= K || vis[i][j]) return;
    if (k == K*K-1) {
        ans++;
        return;
    }
    if (i == K-1 && j == 0) return;
    if (prev == 'R' && (j+1 >= K || vis[i][j+1]) && i-1 >= 0 && i+1 < K && !vis[i-1][j] && !vis[i+1][j]) return;
    if (prev == 'D' && (i+1 >= K || vis[i+1][j]) && j-1 >= 0 && j+1 < K && !vis[i][j-1] && !vis[i][j+1]) return;
    if (prev == 'L' && (j-1 <  0 || vis[i][j-1]) && i-1 >= 0 && i+1 < K && !vis[i-1][j] && !vis[i+1][j]) return;
    if (prev == 'U' && (i-1 <  0 || vis[i-1][j]) && j-1 >= 0 && j+1 < K && !vis[i][j-1] && !vis[i][j+1]) return;
    vis[i][j] = true;
    if      (p[k] == 'R') dfs(i, j+1, k+1, 'R');
    else if (p[k] == 'D') dfs(i+1, j, k+1, 'D');
    else if (p[k] == 'L') dfs(i, j-1, k+1, 'L');
    else if (p[k] == 'U') dfs(i-1, j, k+1, 'U');
    else {
        dfs(i, j+1, k+1, 'R');
        dfs(i+1, j, k+1, 'D');
        dfs(i, j-1, k+1, 'L');
        dfs(i-1, j, k+1, 'U');
    }
    vis[i][j] = false;
}

void solve() {
    cin >> p;
    dfs(0, 0, 0, 'X');
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
