#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> st(n, vector<int>(20, -1));
  for (int i{1}; i < n; ++i) {
    cin >> st[i][1];
    --st[i][1];
  }

  for (int i{2}; i < 20; ++i) {
    for (int j{0}; j < n; ++j) {
      if (st[j][i - 1] != -1) {
        st[j][i] = st[st[j][i - 1]][i - 1];
      }
    }
  }

  int x, k;
  while (q--) {
    cin >> x >> k;
    --x;
    int cur{x};
    while (k && cur != -1) {
      cur = st[cur][__builtin_ctz(k)+1];
      k -= LSOne(k);
    }
    cout << (cur == -1 ? -1 : cur+1) << "\n";
  }

  return 0;
}
