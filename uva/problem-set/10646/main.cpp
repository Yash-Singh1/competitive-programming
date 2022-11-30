#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int on{n};
  while (n--) {
    int cards{27};
    char deck[52][2];

    for (int i{0}; i < 52; ++i) {
      cin >> deck[i][0] >> deck[i][1];
    }

    int y{0};
    for (int i{0}; i < 3; ++i) {
      --cards;
      // cout << deck[cards][0] << deck[cards][1] << " " << (deck[cards][0] >= '2' && deck[cards][0] <= '9') << " " << deck[cards][0] - '0' << "\n";
      if (deck[cards][0] >= '2' && deck[cards][0] <= '9') {
        y += deck[cards][0] - '0';
        cards -= (10 - (deck[cards][0] - '0'));
      } else {
        y += 10;
      }
    }

    // cout << y << " " << cards << "\n";
    cout << "Case " << (on-n) << ": ";
    if (y <= cards) {
      cout << deck[y-1][0] << deck[y-1][1];
    } else {
      cout << deck[y-cards+26][0] << deck[y-cards+26][1];
    }
    cout << "\n";
  }

  return 0;
}
