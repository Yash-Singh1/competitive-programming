#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int wx1, wy1, wx2, wy2;
  pair<pair<int, int>, pair<int, int>> b[2];
  cin >> wx1 >> wy1 >> wx2 >> wy2 >> b[0].first.first >> b[0].first.second >> b[0].second.first >> b[0].second.second >> b[1].first.first >> b[1].first.second >> b[1].second.first >> b[1].second.second;
  for (int i{0}; i < 2; ++i) {
    b[i].first.first = max(b[i].first.first, wx1);
    b[i].first.second = max(b[i].first.second, wy1);
    b[i].second.first = min(b[i].second.first, wx2);
    b[i].second.second = min(b[i].second.second, wy2);
  }
  for (int i{0}; i < 2; ++i) {
    if (b[i].first.first > wx2 || wx1 > b[i].second.first || b[i].first.second > wy2 || wy1 > b[i].second.second) continue;
    if (b[i].second.second - b[i].first.second >= wy2 - wy1) {
      if (b[i].first.first <= wx1) {
        wx1 = b[i].second.first;
        for (int j{0}; j < 2; ++j) b[j].first.first = max(b[j].first.first, wx1);
      }
      if (b[i].second.first >= wx2) {
        wx2 = b[i].first.first;
        for (int j{0}; j < 2; ++j) b[j].second.first = min(b[j].second.first, wx2);
      }
    }
    if (wx2 <= wx1) {
      break;
    }
    if (b[i].second.first - b[i].first.first >= wx2 - wx1) {
      if (b[i].first.second <= wy1) {
        wy1 = b[i].second.second;
        for (int j{0}; j < 2; ++j) b[j].first.second = max(b[j].first.second, wy1);
      }
      if (b[i].second.second >= wy2) {
        wy2 = b[i].first.second;
        for (int j{0}; j < 2; ++j) b[j].second.second = min(b[j].second.second, wy2);
      }
    }
    if (wy2 <= wy1) {
      break;
    }
  }
  if (wy2 <= wy1 || wx2 <= wx1) {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n";
  }
}
