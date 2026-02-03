#include<iostream>
#include<vector>
#include<algorithm>
#define int long long

using namespace std;

int32_t main() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> diff(n + 1, 0);

	while (q--) {

		int l, r;
		cin >> l >> r;

		l--; r--; // to make queries 0-based

		diff[l]++;
		diff[r + 1]--;

	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(diff.begin(), diff.end() - 1, greater<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * diff[i];
	}

	cout << ans << endl;

	return 0;
}
