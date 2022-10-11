#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  while (t--) {
    int w, h, x1, y1, x2, y2, w2, h2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
    if (w - w2 < (x2 - x1) && h - h2 < (y2 - y1)) {
      cout << -1 << "\n";
    } else {
      //double dist{sqrt(pow(abs(min(max(x1, w - x2) - w2, 0)), 2) + pow(abs(min(max(y1, h - y2) - h2, 0)), 2))};
      double dist;
      if (w - w2 < (x2 - x1)) {
        dist = abs(min(max(y1, h - y2) - h2, 0));
      } else if (h - h2 < (y2 - y1)) {
        dist = abs(min(max(x1, w - x2) - w2, 0));
      } else {
        dist = min(abs(min(max(x1, w - x2) - w2, 0)), abs(min(max(y1, h - y2) - h2, 0)));
      }
      
      cout << fixed << setprecision(6) << dist << "\n";
    }
  }
}
