#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string search = "Yes";
  int t;
  cin >> t;

  string s;
  while (t--) {
    cin >> s;
    int i;
    if (s[0] == 'Y') {
      i = 0;
    } else if (s[0] == 'e') {
      i = 1;
    } else if (s[0] == 's') {
      i = 2;
    } else {
      cout << "NO\n";
      continue;
    }
    bool failure{0};
    for (auto &c: s) {
      if (c != search[(i++)%3]) {
        cout << "NO\n";
        failure=1;
        break;
      }
    }
    if (!failure) {
      cout << "YES\n";
    }
  }

  return 0;
}
