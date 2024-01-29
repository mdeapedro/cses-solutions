#include <bits/stdc++.h>
using namespace std;
 
int dx[4] {1, 0, -1, 0};
int dy[4] {0, 1, 0, -1};
char mv[4] {'R', 'D', 'L', 'U'};
array<int, 2> a, b;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
 
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            if      (c == 'A') a = {i, j};
            else if (c == 'B') b = {i, j};
            g[i].push_back(c);
        }
    }
    g[b[0]][b[1]] = '.';
    queue<array<int, 2>> q;
    q.push(a);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            int i = x[0]+dy[k];
            int j = x[1]+dx[k];
            if (i>=0 && i<n && j>=0 && j<m && g[i][j]=='.') {
                g[i][j] = mv[k];
                q.push({i, j});
            }
        }
    }
    if (g[b[0]][b[1]] == '.') {
        cout << "NO\n";
        return;
    }
    string ans = "";
    int i = b[0], j = b[1];
    while (g[i][j] != 'A') {
        if      (g[i][j] == 'R') {j -= 1; ans.push_back('R');}
        else if (g[i][j] == 'D') {i -= 1; ans.push_back('D');}
        else if (g[i][j] == 'L') {j += 1; ans.push_back('L');}
        else                     {i += 1; ans.push_back('U');}
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << '\n' << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
