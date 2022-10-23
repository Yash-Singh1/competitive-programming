#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;

  ll low{0}, high{n - 1};
  vector<pair<ll, ll>> a;
  for (ll i{0}; i < n; ++i) {
    ll x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(a.begin(), a.end());

  while (low < high) {
    if (a[low].first + a[high].first < x) {
      ++low;
    } else if (a[low].first + a[high].first > x) {
      --high;
    } else if (a[low].first + a[high].first == x) {
      cout << min(a[low].second + 1, a[high].second + 1) << " " << max(a[low].second + 1, a[high].second + 1) << "\n";
      return 0;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
