#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q, c;
  cin >> n >> q >> c;

  vector<int> low(n), high(n);
  for (int i{0}; i < n; ++i) {
    low[i] = 1;
    high[i] = c;
  }

  vector<pii> qs(q);
  for (int i{0}; i < q; ++i) {
    cin >> qs[i].first >> qs[i].second;
  }

  sort(qs.begin(), qs.end());
  reverse(qs.begin(), qs.end());

  int a, h;
  for (int i{0}; i < q; ++i) {
    a = qs[i].first; h = qs[i].second;
    int mhigh{1};
    for (int j{0}; j < a; ++j) {
      mhigh = max(mhigh, high[j]);
    }
    if (mhigh >= low[h-1]) {
      low[h-1] = high[h-1];
      for (int j{0}; j < a; ++j) {
        high[j] = low[h-1] - 1;
      }
    } else {
      low[h-1] = mhigh+1;
    }
  }

  ll ans{1};
  for (int i{0}; i < n; ++i) {
    cout << low[i] << ' ' << high[i] << '\n';
    ans *= (high[i] - low[i]) + 1;
    ans %= MOD;
  }

  cout << ans << '\n';

  return 0;
}
