#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
	cin >> n;

	vector<vector<ld>> a(n, vector<ld>(n));
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	vector<ld> p((1<<n));
	p[(1<<n)-1] = 1;
	for (int i{(1<<n)-1}; i >= 0; --i) {
		if (__builtin_popcount(i) <= 1) continue;
		int b{i};
		while (b) {
			for (int j{0}; j < n; ++j) {
				if (j == __builtin_ctz(b) || !(i&(1<<j))) continue;
				p[i^LSOne(b)] += (1.0L / (ld)(__builtin_popcount(i) * (__builtin_popcount(i)-1))) * 2 * p[i] * a[j][__builtin_ctz(b)];
			}
			b -= LSOne(b);
		}
	}

	cout << fixed << setprecision(10);
	for (int i{0}; i < n; ++i) {
		cout << p[1<<i] << " ";
	}
	cout << "\n";

  return 0;
}
