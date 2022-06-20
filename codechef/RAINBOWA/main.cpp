// Gives WA, but initial TCs are fine

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
    bool rainbow{true};
    int last{-1};
    int o[8] {0, 0, 0, 0, 0, 0, 0, 0};
    int seventh{-1};
    for (int i{0}; i < n; ++i) {
      int x;
      cin >> x;
      if (x > 7 || x < 1) {
        rainbow = false;
        break;
      }
      if (last != -1) {
      if (x < last) {
        rainbow = false;
        break;
      } else if (x > last && x - last > 1) {
        rainbow = false;
        break;
      }
      }
      if (x == 7) {
        seventh = i;
        break;
      }
      o[x]++;
      last = x;
    }
    if (seventh == -1) {
      rainbow = false;
    }
    last = -1;
    if (rainbow) {
    for (int i{seventh + 1}; i < n; ++i) {
      int x;
      cin >> x;
      if (last != -1) {
        if (x > last) {
          rainbow = false;
          break;
        }
      }
      --o[x];
      last = x;
    }
    }
    for (int i{1}; i <= 6; ++i) {
      if (o[i] != 0) {
        rainbow = false;
        break;
      }
    }
    if (rainbow) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
