#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int q[26] {};
    for (auto c : s) q[c-'A']++;
    string c1 = "";
    s.clear();
    for (int i=0; i<26; i++) {
        if (q[i]&1) {
            if (c1 == "") c1 = 'A'+i;
            else {
                cout << "NO SOLUTION\n";
                return;
            }
        }
        q[i] >>= 1;
    }
    for (int i=0; i<26; i++) s.append(q[i], 'A'+i);
    s.append(c1);
    for (int i=25; i>=0; i--) s.append(q[i], 'A'+i);
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}