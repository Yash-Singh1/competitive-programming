#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> p2(n);
  p2[0] = 1;
  for (int i{1}; i < n; ++i) {
    p2[i] = (p2[i-1]*2)%MOD;
  }

  vector<pii> p(n*2);
  for (int i{0}; i < n; ++i) {
    cin >> p[i*2].first >> p[i*2+1].first;
    p[i*2].second = -1;
    p[i*2+1].second = 1;
  }

  sort(p.begin(), p.end());
  int c{0};
  int ans{0};
  for (int i{0}; i < 2*n; ++i) {
    c += -p[i].second;
    if (p[i].second == -1) {
      ans += p2[n-c];
      // cout << c << ' ' << n-c << ' ' << p2[n-c] << '\n';
      ans %= MOD;
    }
  }

  cout << ans << '\n';

  return 0;
}
