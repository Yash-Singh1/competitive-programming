#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  char a[3][3];

  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      cin >> a[i][j];
    }
  }

  set<char> s21;
  set<pair<char,char>> s22;
  set<char> s;
  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      s.insert(a[i][j]);
    }
    if (s.size() == 1) {
      s21.insert(*(s.begin()));
    } else if (s.size() == 2) {
      s22.insert({*s.begin(), *(++s.begin())});
    }
    s.clear();
  }

  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      s.insert(a[j][i]);
    }
    if (s.size() == 1) {
      s21.insert(*(s.begin()));
    } else if (s.size() == 2) {
      s22.insert({*s.begin(), *(++s.begin())});
    }
    s.clear();
  }

  for (int i{0}; i < 3; ++i) {
    s.insert(a[i][i]);
  }
  if (s.size() == 1) {
    s21.insert(*(s.begin()));
  } else if (s.size() == 2) {
    s22.insert({*s.begin(), *(++s.begin())});
  }
  s.clear();

  for (int i{0}; i < 3; ++i) {
    s.insert(a[i][2 - i]);
  }
  if (s.size() == 1) {
    s21.insert(*(s.begin()));
  } else if (s.size() == 2) {
    s22.insert({*s.begin(), *(++s.begin())});
  }

  cout << s21.size() << "\n" << s22.size() << "\n";

  return 0;
}
