#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, w;
	cin >> n >> w;

	vector<pair<long double,pair<int,int>>> items(n);
	for (int i{0}; i < n; ++i) {
		cin >> items[i].second.first >> items[i].second.second;
		items[i].first = (long double)items[i].second.second / items[i].second.first;
	}

	sort(items.begin(), items.end(), greater<pair<long double,pair<int,int>>>());

	cout << fixed << setprecision(10);
	int i{0};
	long double ans{0};
	while (w && i < n) {
		if (items[i].second.first < w) {
			w -= items[i].second.first;
			ans += items[i].second.second;
		} else {
			ans += items[i].first * w;
			w = 0;
			break;
		}
		++i;
	}

	cout << ans << "\n";

	return 0;
}
