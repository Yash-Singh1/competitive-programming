#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);

  int n, k, a1, a2, b1, b2;
  cin >> n >> k >> a1 >> a2 >> b1 >> b2;
  --a1; --a2; --b1; --b2;

  vector<int> pattern[n];
  for (int i{0}; i < n; ++i) {
    int cur{i};
    int steps{0};
    do {
      pattern[i].push_back(cur);
      ++steps;
      if (cur >= a1 && cur <= a2) {
        cur = a1 + (a2 - cur);
      }
      if (cur >= b1 && cur <= b2) {
        cur = b1 + (b2 - cur);
      }
      // cout << cur << " ";
    } while (cur != i);
    // cout << "\n";
  }

  vector<pair<int,int>> finale(n);

  for (int i{0}; i < n; ++i) {
    finale[i] = {(pattern[i][(k % pattern[i].size())]+1), i};
  }

  sort(finale.begin(), finale.end());
  for (auto &p: finale) {
    cout << p.second+1 << "\n";
  }

  return 0;
}
