#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;
  pair<pair<ll,ll>,ll> updates[n];
  pair<ll,ll> queries[q];

  vector<ll> indicies((n+q)*2);
  ll tot{0};
  for (ll i{0}; i < n; ++i) {
    cin >> updates[i].first.first >> updates[i].first.second >> updates[i].second;
    indicies[tot++] = updates[i].first.first;
    indicies[tot++] = updates[i].first.second;
  }
  for (ll i{0}; i < q; ++i) {
    cin >> queries[i].first >> queries[i].second;
    indicies[tot++] = queries[i].first;
    indicies[tot++] = queries[i].second;
  }
  sort(indicies.begin(), indicies.end());
  indicies.erase(unique(indicies.begin(), indicies.end()), indicies.end());

  unordered_map<ll,ll>m;
  for (ll i{0}; i < (ll)indicies.size(); ++i) {
    m.insert({indicies[i], i});
  }

  ll diff[(ll)indicies.size()];
  for (ll i{0}; i < (ll)indicies.size(); ++i) {
    diff[i] = 0;
  }
  for (ll i{0}; i < n; ++i) {
    diff[m[updates[i].first.first]] += updates[i].second;
    diff[m[updates[i].first.second]] -= updates[i].second;
  }

  for (ll i{1}; i < (ll)indicies.size(); ++i) {
    diff[i] += diff[i - 1];
  }

  for (ll i{0}; i < (ll)indicies.size() - 1; ++i) {
    diff[i] *= indicies[i + 1] - indicies[i];
  }

  for (ll i{1}; i < (ll)indicies.size(); ++i) {
    diff[i] += diff[i - 1];
  }

  for (ll i{0}; i < q; ++i) {
    cout << diff[m[queries[i].second] - 1] - (indicies[0] == queries[i].first ? 0 : diff[m[queries[i].first] - 1]) << "\n";
  }

  return 0;
}
