#include <bits/stdc++.h>

using namespace std;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

  int b1x1{0}, b1y1{0}, b1x2{0}, b1y2{0}, b2x1{0}, b2y1{0}, b2x2{0}, b2y2{0};
  cin >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2;

  if (b2x1 <= b1x1 && b2x2 >= b1x2 && b2y1 <= b1y1 && b2y2 >= b1y2) {
    cout << 0 << "\n";
  } else if (b2x2 < b1x1 || b2x1 > b1x2 || b2y1 > b1y2 || b2y2 < b1y1) {
    cout << ((b1x2 - b1x1) * (b1y2 - b1y1)) << "\n";
  } else {
    // Trim behind backboard by same concept used in white sheet codeforces
    b2x1 = max(b1x1, b2x1);
    b2y1 = max(b1y1, b2y1);
    b2x2 = min(b2x2, b1x2);
    b2y2 = min(b2y2, b1y2);
    if (b2x2 - b2x1 == b1x2 - b1x1) {
      if (b1y1 == b2y1) {
        b1y1 = b2y2;
      } else if (b2y2 == b1y2) {
        b1y2 = b2y1;
      }
    } else if (b2y2 - b2y1 == b1y2 - b1y1) {
      if (b1x1 == b2x1) {
        b1x1 = b2x2;
      } else if (b1x2 == b2x2) {
        b1x2 = b2x1;
      }
    }
    cout << ((b1x2 - b1x1) * (b1y2 - b1y1)) << "\n";
  }
}
