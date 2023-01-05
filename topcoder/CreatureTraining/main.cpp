#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, d;
ll power[50];
ll counters[50];
vector<vector<map<__int128,ll>>> dp(101, vector<map<__int128,ll>>(51));
ll mls{0};

__int128 splitmix64(__int128 x) {
  // http://xorshift.di.unimi.it/splitmix64.c
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}

// IDK trying to hash stuff with random numbers
__int128 hasher() {
  pair<__int128, __int128> ans {0,0};
  for (ll i{0}; i < 25 && i < n; ++i) {
    ans.second <<= 5;
    ans.second += counters[i];
  }
  for (ll i{25}; i < 50 && i < n; ++i) {
    ans.first <<= 5;
    ans.first += counters[i];
  }
  const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
  return splitmix64(ans.first + FIXED_RANDOM)^(splitmix64(ans.second + FIXED_RANDOM) >> 1);
}

ll calc(ll tot, ll id) {
  __int128 h = hasher();
  if (dp[tot][id].find(h) != dp[tot][id].end()) {
    return dp[tot][id][h];
  }
  if (tot == d || id >= n-1) {
    ll ans{0};
    for (ll i{0}; i < n; ++i) {
      ans += counters[i] * power[i];
    }
    return (dp[tot][id][h] = ans);
  }
  ll ans{INT_MIN};
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

class CreatureTraining {
  public:
    long long maximumPower(vector <int> count, vector <int> powery, int D ) {
        int i{0};
        for (auto &c: count) {
            counters[i] = c;
            ++i;
        }
        i = 0;
        for (auto &p: powery) {
            power[i] = p;
            ++i;
        }
        n = count.size();
        d = D;
        return calc(0, 0);
    }
};
