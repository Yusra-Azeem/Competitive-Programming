#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    // Build Sparse Table
    int K = log2(n) + 1;
    vector<vector<long long>> st(n + 1, vector<long long>(K + 1));

    // Initialize for intervals of length 1
    for (int i = 1; i <= n; i++) st[i][0] = h[i];

    // Compute values for larger intervals
    for (int j = 1; j <= K; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    // Answer queries
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = log2(r - l + 1);
        long long ans = min(st[l][len], st[r - (1 << len) + 1][len]);
        cout << ans << '\n';
    }

    return 0;
}
