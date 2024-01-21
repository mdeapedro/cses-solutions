#include <bits/stdc++.h>
using namespace std;

int main() {
    const int K=6, M=1e9+7;
    int n;
    long long d[K];
    fill(d, d+K, 1);
    cin >> n;
    for (int i=1; i<K; i++) {
        for (int j=0; j<i; j++) {
            d[i] += d[j];
        }
    }
    for (int i=K; i<n; i++) {
        for (int j=1; j<K; j++) {
            d[i%K] += d[(i+j)%K];
        }
        d[i%K] %= M;
    }
    cout << d[(n-1)%K] << '\n';
}
