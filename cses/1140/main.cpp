#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> decompress;
  vector<pair<pii,ll>> tasks(n);
  for (ll i{0}; i < n; ++i) {
    cin >> tasks[i].first.first >> tasks[i].first.second >> tasks[i].second;
    decompress.push_back(tasks[i].first.first);
    decompress.push_back(tasks[i].first.second);
  }
  decompress.push_back(0);

  sort(decompress.begin(), decompress.end());
  decompress.erase(unique(decompress.begin(), decompress.end()), decompress.end());
  unordered_map<ll,ll> compress;
  for (ll i{0}; i < decompress.size(); ++i) {
    compress[decompress[i]] = i;
  }

  for (ll i{0}; i < n; ++i) {
    tasks[i].first.first = compress[tasks[i].first.first];
    tasks[i].first.second = compress[tasks[i].first.second];
  }
  sort(tasks.begin(), tasks.end());

  vector<ll> dp(decompress.size()+1, 0);
  ll cur{0};
  for (ll j{0}; j < decompress.size(); ++j) {
    dp[j + 1] = max(dp[j], dp[j + 1]);
    ll ocur{cur};
    while (ocur < n && tasks[ocur].first.first < j) {
      ++ocur;
    }
    // cur = ocur;
    // while (cur < n && tasks[cur].first.first == j) {
    //   ++cur;
    // }
    for (cur = ocur; cur < n && tasks[cur].first.first == j; ++cur) {
      dp[tasks[cur].first.second+1] = max(dp[j] + tasks[cur].second, dp[tasks[cur].first.second+1]);
    }
  }

  // for (ll i{0}; i < decompress.size(); ++i) {
  //   cout << decompress[i] << " " << dp[i] << "\n";
  // }

  cout << dp[decompress.size()] << "\n";

  return 0;
}
