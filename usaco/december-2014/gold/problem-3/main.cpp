#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);

  int n, t;
  cin >> n >> t;

  vector<pll> cows(n);
  for (int i{0}; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second;
    cows[i].second *= t;
    cows[i].second += cows[i].first;
  }

  reverse(cows.begin(), cows.end());

  vector<ll> lis;
  for (int i{0}; i < n; ++i) {
    auto it = upper_bound(lis.begin(), lis.end(), cows[i].second);
    if (it == lis.end()) {
      lis.push_back(cows[i].second);
    } else {
      lis[it - lis.begin()] = cows[i].second;
    }
  }

  cout << lis.size() << "\n";

  return 0;
}
