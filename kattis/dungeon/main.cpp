// TC 2 fails but IDK

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int>>> movement;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  movement.push_back({0, {0, 1}});
  movement.push_back({0, {1, 0}});
  movement.push_back({1, {0, 0}});
  movement.push_back({0, {0, -1}});
  movement.push_back({0, {-1, 0}});
  movement.push_back({-1, {0, 0}});

  while (true) {
    int l, r, c;
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0) break;
    pair<int, pair<int, int>> start;
    int d[l][r][c];
    for (int i{0}; i < l; ++i) {
      for (int j{0}; j < r; ++j) {
        for (int k{0}; k < c; ++k) {
          char x;
          cin >> x;
          if (x == 'S') {
            d[i][j][k] = 0;
            start.first = i;
            start.second.first = j;
            start.second.second = k;
          } else if (x == 'E') {
            d[i][j][k] = -2;
          } else if (x == '.') {
            d[i][j][k] = -1;
          } else if (x == '#') {
            d[i][j][k] = -3;
          }
        }
      }
    }
    stack<pair<int, pair<int, int>>> s;
    s.push(start);
    bool success{false};
    while (!s.empty()) {
      pair<int, pair<int, int>> next = s.top();
      s.pop();
      for (auto &p: movement) {
        pair<int, pair<int, int>> pr;
        pr.first = p.first + next.first;
        pr.second.first = p.second.first + next.second.first;
        pr.second.second = p.second.second + next.second.second;
        if (pr.first < 0 || pr.first > l - 1 || pr.second.first < 0 || pr.second.first > r - 1 || pr.second.second < 0 || pr.second.second > c - 1) continue;
        int aVal = d[pr.first][pr.second.first][pr.second.second];
        if (aVal == -3) {
          continue;
        } else if (aVal == -1) {
          s.push(pr);
          d[pr.first][pr.second.first][pr.second.second] = d[next.first][next.second.first][next.second.second] + 1;
        } else if (aVal == -2) {
          cout << "Escaped in " << d[next.first][next.second.first][next.second.second] + 1 << " minute(s)." << endl;
          success = true;
          while (!s.empty()) s.pop();
          break;
        }
      }
    }
    if (!success) {
      cout << "Trapped!" << endl;
    }
  }
}
