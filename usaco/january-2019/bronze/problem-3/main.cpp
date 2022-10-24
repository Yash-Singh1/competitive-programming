#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);

  int n;
  cin >> n;

  vector<string> characters[n];

  for (int i{0}; i < n; ++i) {
    string s;
    int k;
    cin >> s >> k;
    while (k--) {
      cin >> s;
      characters[i].push_back(s);
    }
  }

  int ans{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != j) {
        int inter{0};
        for (auto &characteristic: characters[i]) {
          for (auto &characteristic2: characters[j]) {
            if (characteristic == characteristic2) {
              ++inter;
            }
          }
        }
        ans = max(ans,inter+1);
      }
    }
  }

  cout << ans;

  return 0;
}
