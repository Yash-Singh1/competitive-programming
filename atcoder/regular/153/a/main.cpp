#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ll first{110000000};
  for (int i{1}; i < n; ++i) {
    if (first % 100 / 10 == 9) {
      first -= 90;
      if (first % 10 == 9) {
        first -= 909;
        if (first % 10000 / 1000 == 9) {
          first -= 99000;
          if (first % 1000000 / 100000 == 9) {
            first -= 900000;
            if (first % 10000000 / 1000000 == 9) {
              first -= 9000000;
              first += 110000000;
            } else {
              first += 1000000;
            }
          } else {
            first += 100000;
          }
        } else {
          first += 11000;
        }
      } else {
        first += 101;
      }
    } else {
      first += 10;
    }
  }

  cout << first << "\n";

  return 0;
}
