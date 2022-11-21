#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);

  ll k, n;
  cin >> k >> n;

  ll x, speed, left, t;
  while (n--) {
    cin >> x;
    speed = 0;
    left = k;
    t = 0;
    while (left > 0) {
      if (speed < x) {
        ++speed;
      } else if ((speed+2)*(speed+1)/2-(x)*(x-1)/2 <= left) {
        ++speed;
      } else if ((speed+1)*(speed)/2-(x)*(x-1)/2 > left) {
        --speed;
      }
      left -= speed;
      ++t;
    }
    cout << t << "\n";
  }

  return 0;
}
