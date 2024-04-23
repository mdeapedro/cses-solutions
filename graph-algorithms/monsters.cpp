#include <bits/stdc++.h>
using namespace std;

const int K = 4;
int dx[K] {1, 0, -1, 0};
int dy[K] {0, 1, 0, -1};
char dir[K] {'L', 'U', 'R', 'D'};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (m));
    queue<array<int, 3>> q;
    array<int, 2> A, B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if      (c == '#') g[i][j] = 6;
            else if (c == '.') g[i][j] = 7;
            else if (c == 'M') {
                g[i][j] = 7;
                q.push({i, j, 5});
            } else {
                g[i][j] = 7;
                A = {i, j};
            }
        }
    }
    bool found = false;
    q.push({A[0], A[1], 4});
    while (!q.empty()) {
        auto [i, j, t] = q.front();
        q.pop();
        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] != 7) continue;
        g[i][j] = t;
        if (t != 5 && (i == 0 || i == n-1 || j == 0 || j == m-1)) {
            found = true;
            B = {i, j};
            break;
        }
        for (int k = 0; k < K; k++) q.push({i + dy[k], j + dx[k], t == 5 ? t : k});
    }
    if (!found) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    stack<char> ans;
    while (B != A) {
        int t = (g[B[0]][B[1]] + 2) % K;
        ans.push(dir[t]);
        B[0] += dy[t];
        B[1] += dx[t];
    }
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
