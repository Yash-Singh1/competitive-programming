#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  char s[52];
  for (int i{0}; i < 52; ++i) {
    cin >> s[i];
  }

  pair<int,int> cross[26];
  for (int i{0}; i < 26; ++i) {
    bool first{1};
    for (int j{0}; j < 52; ++j) {
      if (s[j]-'A' == i) {
        if (first) {
          first = 0;
          cross[i].first = j;
        } else {
          cross[i].second = j;
          goto finish;
        }
      }
    }
    finish: continue;
  }

  int tot{0};
  for (int i{0}; i < 26; ++i) {
    for (int j{0}; j < 26; ++j) {
      if (i != j && cross[i].first < cross[j].first && cross[i].second < cross[j].second && cross[i].second > cross[j].first) {
        ++tot;
      }
    }
  }

  cout << tot << "\n";

  return 0;
}
