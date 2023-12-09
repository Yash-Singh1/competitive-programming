#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  
  vector<int> g(n), gl(n);
  for (int i{0}; i < n; ++i) {
    cin >> gl[i] >> g[i]; --gl[i]; --g[i];
  }

  char x; int cur{0};
  vector<int> movement(m);
  for (int i{0}; i < m; ++i) {
    cin >> x;
    if (x == 'L') movement[i] = 0;
    else movement[i] = 1;
  }

  vector<int> t(n, -1);
  int curt{-1};
  while (t[cur] == -1) {
    // cout << cur+1 << '\n';
    ++curt;
    if (curt == k) {
      // cout << "hit early\n";
      cout << cur+1 << '\n';
      return 0;
    }
    t[cur] = curt;
    // cout << "MOVEMENT: ";
    for (int i{0}; i < m; ++i) {
      // cout << cur+1 << '/' << movement[i] << ' ';
      if (movement[i]) {
        cur = g[cur];
      } else {
        cur = gl[cur];
      }
    }
    // cout << '\n';
    // cout << "AFTER: " << cur+1 << '\n';
  }
  // cout << "HITPOINT: " << cur+1 << ' ' << curt << ' ' << t[cur] << '\n';
  ++curt;
  k -= t[cur];
  k %= curt - t[cur];
  while (k--) {
    for (int i{0}; i < m; ++i) {
      if (movement[i]) {
        cur = g[cur];
      } else {
        cur = gl[cur];
      }
    }
  }

  cout << cur+1 << '\n';

  return 0;
}
