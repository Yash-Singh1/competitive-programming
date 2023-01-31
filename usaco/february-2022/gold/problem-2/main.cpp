#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(22);

  ll t, k;
  cin >> t >> k;
  --t;

  // E(x) = (chance worse * E(x - 1)) + expected better

  vector<vector<ld>> comb(t + 1, vector<ld>(t + 1));
  comb[0][0] = 1;
  for (int i{1}; i <= t; ++i) {
    comb[i][0] = comb[i - 1][0] / 2;
    for (int j{1}; j <= t; ++j) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) / 2;
    }
  }

  vector<ld> prep(t + 1);
  prep[0] = comb[t][0];
  for (int i{1}; i <= t; ++i) {
    prep[i] = prep[i - 1] + comb[t][i];
  }

  vector<ld> prev(t + 1);
  prev[0] = 0;
  for (int i{1}; i <= t; ++i) {
    prev[i] = prev[i - 1] + comb[t][i] * i;
  }

  ld ev{0};
  while (k > 0) {
    ld prob{prep[floor(ev)]}, moreev{prev[t] - prev[floor(ev)]};
    ll l{0}, r{(ll)1e9}, ans{-1};
    while (l <= r) {
      ll m{(l+r)/2};
      if (floor((moreev * ((pow(prob, m) - 1) / (prob - 1))) + pow(prob, m) * ev) == floor(ev)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    assert(ans != -1);
    ++ans;
    ans = min(k, ans);
    k -= ans;
    ev = (moreev * ((pow(prob, ans) - 1) / (prob - 1))) + pow(prob, ans) * ev;
  }
  ++ev;

  cout << ev << "\n";

  return 0;
}
