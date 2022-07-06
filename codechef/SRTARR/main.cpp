#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int last{-1};
    int zers{0};
    for (auto ch: a) {
      if (last == -1 && ch == '0') {
        continue;
      } else {
        if (ch == '0' && last == '1') {
          ++zers;
        }
        last = ch;
      }
    }
    cout << zers << endl;
  }
}
