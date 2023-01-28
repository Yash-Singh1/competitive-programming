#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  string s; cin >> s;
  map<char, bool> pos;
  char x;
  ll ans{0};
  for (int i{0}; i < k; ++i) {
    cin >> x;
    pos[x] = 1;
  }

  for (int i{0}; i < n; ++i) {
    if (!pos[s[i]]) continue;
    int oi{i};
    while (i < n && pos[s[i]]) ++i;
    --i;
    ans += (ll)(i - oi + 1) * (ll)(i - oi + 2) / 2LL;
  }

  cout << ans << "\n";

  return 0;
}
