#include <bits/stdc++.h>

using namespace std;

int n, d;
int power[50];
int counters[50];
vector<vector<map<pair<__int128,__int128>,int>>> dp(101, vector<map<pair<__int128,__int128>,int>>(51));
int mls{0};

pair<__int128, __int128> hasher() {
  pair<__int128, __int128> ans {0,0};
  for (int i{0}; i < 25 && i < n; ++i) {
    ans.second <<= 5;
    ans.second += counters[i];
  }
  for (int i{25}; i < 50 && i < n; ++i) {
    ans.first <<= 5;
    ans.first += counters[i];
  }
  return ans;
}

int calc(int tot, int id) {
  pair<__int128, __int128> h = hasher();
  if (dp[tot][id].find(h) != dp[tot][id].end()) {
    return dp[tot][id][h];
  }
  if (tot == d || id >= n-1) {
    int ans{0};
    for (int i{0}; i < n; ++i) {
      ans += counters[i] * power[i];
    }
    return (dp[tot][id][h] = ans);
  }
  int ans{INT_MIN};
  assert(counters[id] >= 0);
  if (counters[id] > 0) {
    --counters[id];
    ++counters[id + 1];
    ans = max(ans, calc(tot + 1, id));
    ++counters[id];
    --counters[id + 1];
  }
  ans = max(ans, calc(tot, id + 1));
  return (dp[tot][id][h] = ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> d >> n;

  for (int i{0}; i < n; ++i) {
    cin >> counters[i];
  }
  for (int i{0}; i < n; ++i) {
    cin >> power[i];
  }

  cout << calc(0, 0) << "\n";

  return 0;
}
