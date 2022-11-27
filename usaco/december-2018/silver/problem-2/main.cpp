#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("convention2.in", "r", stdin);
  freopen("convention2.out", "w", stdout);

  ll n;
  cin >> n;

  vector<pair<ll,pair<ll,ll>>> staging(n);
  for (ll i{0}; i < n; ++i) {
    cin >> staging[i].first >> staging[i].second.second;
    staging[i].second.first = i;
  }
  sort(staging.begin(), staging.end());

  ll stagepos{0};
  set<pair<ll,pair<ll,ll>>> waiting;
  ll t{0}, ans{0};
  while (stagepos < (ll)staging.size()) {
    if (staging[stagepos].first < t || waiting.empty()) {
      ll stageposo{stagepos};
      while (stagepos < (ll)staging.size() && (staging[stageposo].first >= t ? staging[stagepos].first == staging[stageposo].first : staging[stagepos].first <= t)) {
        ++stagepos;
      }
      for (ll i{stageposo}; i < stagepos; ++i) {
        waiting.insert({staging[i].second.first, {staging[i].first, staging[i].second.second}});
      }
    }
    if (!waiting.empty()) {
      ans = max(ans, max(0LL, t - waiting.begin()->second.first));
      t = max(t, waiting.begin()->second.first) + waiting.begin()->second.second;
      waiting.erase(waiting.begin());
    }
  }
  while (!waiting.empty()) {
    ans = max(ans, max(0LL, t - waiting.begin()->second.first));
    t = max(t, waiting.begin()->second.first) + waiting.begin()->second.second;
    waiting.erase(waiting.begin());
  }

  cout << ans << "\n";

  return 0;
}
