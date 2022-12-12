#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  char state{s[0]};
  for (int k{0}; k < 3; ++k) {
    int adjustments{0};
    for (int i{1}; i < (int)s.size(); ++i) {
      if (state != s[i]) {
        ++adjustments;
        state = s[i];
      }
      if (k == 0) {
        if (state != 'U') ++adjustments;
        state = 'U';
      } else if (k == 1) {
        if (state != 'D') ++adjustments;
        state = 'D';
      } else {
        state = s[i];
      }
    }
    state = s[0];
    cout << adjustments << "\n";
  }

  return 0;
}
