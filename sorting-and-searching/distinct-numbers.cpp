#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x[200000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    sort(x, x+n);
    cout << unique(x, x+n)-x << '\n';
}
