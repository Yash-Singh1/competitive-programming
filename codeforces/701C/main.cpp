#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  map<char,int>u;
  for (int i{0}; i < n; ++i) {
    ++u[s[i]];
  }
  int unique{(int)u.size()};

  map<char, int> m;
  int l{0}, r{0}, mn{n};
  while (l < n) {
    while (r < n && (int)m.size() < unique) {
      ++m[s[r]];
      ++r;
    }
    if ((int)m.size() == unique) {
      mn = min(r-l, mn);
    }
    --m[s[l]];
    if (m[s[l]] == 0) m.erase(s[l]);
    ++l;
  }

  cout << mn << "\n";

  return 0;
}
