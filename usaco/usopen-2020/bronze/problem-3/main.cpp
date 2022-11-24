#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  int n, t;
  cin >> n >> t;

  bool infected[n];
  char x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x == '0') {
      infected[i] = 0;
    } else {
      infected[i] = 1;
    }
  }

  pair<int,pair<int,int>> timeline[t];
  for (int i{0}; i < t; ++i) {
    cin >> timeline[i].first >> timeline[i].second.first >> timeline[i].second.second;
    --timeline[i].second.first; --timeline[i].second.second;
  }
  sort(timeline, timeline + t);

  bool infect_test[n];
  int hoove_shakes_left[n];
  bool zero[n];
  for (int i{0}; i <n; ++i) {
    zero[i] = 0;
  }
  int smallk{INT_MAX}, largek{INT_MIN};
  for (int i{0}; i < n; ++i) {
    int smallpos{-1}, largepos{-1};
    for (int k{0}; k < t; ++k) {
      for (int j{0}; j < n; ++j) {
        infect_test[j] = 0;
      }
      infect_test[i] = 1;
      for (int j{0}; j < n; ++j) {
        hoove_shakes_left[j] = 0;
      }
      hoove_shakes_left[i] = k;
      for (int time{0}; time < t; ++time) {
        if ((infect_test[timeline[time].second.first] && hoove_shakes_left[timeline[time].second.first]) || (infect_test[timeline[time].second.second] && hoove_shakes_left[timeline[time].second.second])) {
          if (infect_test[timeline[time].second.first] && hoove_shakes_left[timeline[time].second.first] > 0) {
            --hoove_shakes_left[timeline[time].second.first];
          } else if (!infect_test[timeline[time].second.first]) {
            hoove_shakes_left[timeline[time].second.first] = k;
          }
          if (infect_test[timeline[time].second.second] && hoove_shakes_left[timeline[time].second.second] > 0) {
            --hoove_shakes_left[timeline[time].second.second];
          } else if (!infect_test[timeline[time].second.second]) {
            hoove_shakes_left[timeline[time].second.second] = k;
          }
          infect_test[timeline[time].second.first] = 1;
          infect_test[timeline[time].second.second] = 1;
        }
      }
      bool consistent = 1;
      for (int i{0}; i < n; ++i) {
        if (infected[i] != infect_test[i]) {
          consistent = 0;
          break;
        }
      }
      if (consistent && smallpos == -1) {
        smallpos = k;
      }
      if (consistent) {
        largepos = k;
      }
    }
    if (largepos != -1) {
      zero[i] = 1;
      largek = max(largepos, largek);
      smallk = min(smallpos, smallk);
    }
  }

  int totz{0};
  for (int i{0}; i < n; ++i) {
    if (zero[i]) ++totz;
  }

  cout << totz << " " << smallk << " ";
  if (largek == t-1) {
    cout << "Infinity";
  } else {
    cout << largek;
  }
  cout << "\n";

  return 0;
}
