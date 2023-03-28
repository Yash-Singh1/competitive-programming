// Lots of WA, but good example of bitmasks and meet in middle

#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, q;
	cin >> n >> p >> q;
	int x, y;
	int d = gcd(p, q);
	p /= d;
	q /= d;

	vector<pair<int,pair<int,int>>> cake(n);
	for (int i{0}; i < n; ++i) {
		cin >> cake[i].second.first >> cake[i].second.second >> cake[i].first;
	}

	int firstn{n/2};
	vector<int> almond(1<<firstn), berry(1<<firstn), cost(1<<firstn);
	map<pair<int,int>,int> aval;
	int ans{INT_MAX};
	aval[{0, 0}] = 0;
	for (int i{1}; i < (1<<firstn); ++i) {
		almond[i] = almond[i - LSOne(i)] + cake[__builtin_ctz(i)].second.first;
		berry[i] = berry[i - LSOne(i)] + cake[__builtin_ctz(i)].second.second;
		cost[i] = cost[i - LSOne(i)] + cake[__builtin_ctz(i)].first;
		d = gcd(almond[i], berry[i]);
		if (aval.find({almond[i]/d, berry[i]/d}) == aval.end()) {
			aval[{almond[i]/d, berry[i]/d}] = cost[i];
		}
		if (almond[i] / d == p && berry[i] / d == q) {
			ans = min(ans, cost[i]);
		}
		aval[{almond[i]/d, berry[i]/d}] = min(aval[{almond[i]/d, berry[i]/d}], cost[i]);
	}

	int secondn{n-firstn};
	almond.resize(1<<secondn);
	berry.resize(1<<secondn);
	cost.resize(1<<secondn);
	for (int i{1}; i < (1<<secondn); ++i) {
		almond[i] = almond[i - LSOne(i)] + cake[__builtin_ctz(i)+firstn].second.first;
		berry[i] = berry[i - LSOne(i)] + cake[__builtin_ctz(i)+firstn].second.second;
		cost[i] = cost[i - LSOne(i)] + cake[__builtin_ctz(i)+firstn].first;
		d = gcd(almond[i], berry[i]);
		if (almond[i] / d == p && berry[i] / d == q) {
			ans = min(ans, cost[i]);
		}
		int roundupp = (max(almond[i], berry[i]) + p) / p * p;
		int roundupb = (max(almond[i], berry[i]) + q) / q * q;
		int al = roundupp - almond[i];
		int be = roundupb - berry[i];
		d = gcd(al, be);
		al /= d;
		be /= d;
		if (aval.find({al, be}) == aval.end()) continue;
		else {
			ans = min(ans, aval[{al, be}] + cost[i]);
		}
	}

	cout << (ans == INT_MAX ? -1 : ans) << '\n';

  return 0;
}
