#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct sort_pair {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b) const {
      if (a.first == b.first) {
        return a.second > b.second;
      }
      return a.first < b.first;
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  // vector<pair<ll,ll>> points(2*n);
  // vector<pair<ll,ll>> indices(2*n);
  map<pair<ll,ll>,ll,sort_pair> m;
  ll x, y;
  for (ll i{0}; i < n; ++i) {
    cin >> x >> y;
    ++m[{x, 1}];
    ++m[{y, -1}];
  }
  // sort(indices.begin(), indices.end(), sort_pair);
  // indices.erase(unique(indices.begin(), indices.end()), indices.end());

  // ll diff[(ll)indices.size()];
  // for (ll i{0}; i < (ll)indices.size(); ++i) {
  //   diff[i] = 0;
  // }

  // for (ll i{0}; i < 2*n; ++i) {
  //   diff[find(indices.begin(), indices.end(), points[i]) - indices.begin()] += points[i].second;
  // }

  ll ans[n];
  for (ll i{0}; i < n; ++i) {
    ans[i] = 0;
  }
  ll sm{m.begin()->second * m.begin()->first.second-1};
  for (auto it = next(m.begin()); it != m.end(); it = next(it)) {
    if (sm == -1LL) goto skippers;
    ans[sm] += it->first.first - prev(it)->first.first + ((it->first.second < 0 && prev(it)->first.second > 0) ? 1LL : ((it->first.second > 0 && prev(it)->first.second < 0) ? -1LL : 0LL));
    skippers: {}
    sm += it->second * it->first.second;
  }

  for (ll i{0}; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
