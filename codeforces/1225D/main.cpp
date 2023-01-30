#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> mdiv(100001);
  for (int i{2}; i <= 100000; ++i) {
    if (mdiv[i] != 0) continue;
    for (int j{i}; j <= 100000; j += i) {
      mdiv[j] = i;
    }
  }

  map<vector<pii>,int> m;
  int x;
  ll ans{0};
  for (int i{0}; i < n; ++i) {
    cin >> x;
    vector<pii> primefinv;
    vector<pii> primef;
    while (x > 1) {
      int prime{mdiv[x]}, tot{0};
      while (x % prime == 0) {
        x /= prime;
        ++tot;
      }
      tot %= k;
      if (tot) {
        primef.push_back({prime, tot});
      }
      tot = (((k - tot)%k)+k)%k;
      if (tot) {
        primefinv.push_back({prime, tot});
      }
    }
    ans += m[primefinv];
    ++m[primef];
  }

  cout << ans << '\n';

  return 0;
}
