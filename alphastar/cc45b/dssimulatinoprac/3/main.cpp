#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> bracelet(m);
    vector<int> occur(n);
    for (int i{0}; i < m; ++i) {
      bracelet[i].reserve(2*n);
    }
    int k, x;
    for (int i{0}; i < m; ++i) {
      cin >> k;
      for (int j{0}; j < k; ++j) {
        cin >> x; --x;
        ++occur[x];
        bracelet[i].push_back(x);
      }
    }

    vector<int> start(n, -1), end(n, -1);
    for (int i{0}; i < m; ++i) {
      for (auto &spot: bracelet[i]) {
        if (start[spot] < 0) {
          start[spot] = i;
        }
        end[spot] = i;
      }
    }

    vector<int> startx(n, -1), endx(n, -1), lastappear(n, -1);
    deque<int> match, cur;
    bool win{1};
    vector<int> order;
    vector<int> p(n, -1);
    for (int i{0}; i < m; ++i) {
      for (int j{0}; j < n; ++j) {
        startx[j] = -1;
        endx[j] = -1;
      }
      for (int j{0}; j < (int)bracelet[i].size(); ++j) {
        if (startx[bracelet[i][j]] < 0) {
          startx[bracelet[i][j]] = j;
        }
        endx[bracelet[i][j]] = j;
      }
      stack<int> s;
      vector<int> cur_order;
      for (int j{0}; j < (int)bracelet[i].size(); ++j) {
        if (j == startx[bracelet[i][j]]) {
          if (p[bracelet[i][j]] == -1) {
            // cout << bracelet[i][j] << ' ' << p[bracelet[i][j]] << '\n';
            if (s.size()) {
              p[bracelet[i][j]] = s.top();
            } else {
              p[bracelet[i][j]] = INT_MAX;
            }
          } else {
            if ((p[bracelet[i][j]] == INT_MAX && s.size()) || (p[bracelet[i][j]] != INT_MAX && (s.empty() || s.top() != p[bracelet[i][j]]))) {
              win = 0;
              break;
            }
          }
          s.push(bracelet[i][j]);
          if (i > start[bracelet[i][j]]) {
            if (match.front() == bracelet[i][j]) match.pop_front();
            else {
              win = 0;
              break;
            }
            cur_order.push_back(bracelet[i][j]);
            if (lastappear[bracelet[i][j]] != i-1) {
              win = 0;
              break;
            }
          }
          if (i < end[bracelet[i][j]]) {
            lastappear[bracelet[i][j]] = i;
            cur.push_back(bracelet[i][j]);
          }
        } else {
          if (s.top() == bracelet[i][j]) s.pop();
          else {
            win = 0;
            break;
          }
        }
      }
      if (!win) break;
      for (int k{0}; k < n; ++k) {
        if (start[k] > i || end[k] < i) continue;
        bool oneExists{0};
        for (int j{0}; j < (int)bracelet[i].size(); ++j) {
          if (bracelet[i][j] == k) {
            oneExists = 1;
            break;
          }
        }
        if (!oneExists) {
          win = 0;
          break;
        }
      }
      // for (int i{0}; i < n; ++i) {
      //   if (occur[i] == 1) win = 0;
      // }
      // if (!win) break;
      swap(match, cur);
      if (cur.size()) {
        win = 0;
        break;
      }
      int l{0};
      for (auto &cure: cur_order) {
        while (l != (int)order.size() && count(cur_order.begin(), cur_order.end(), order[l]) == 0) ++l;
        if (count(order.begin(), order.end(), cure) == 0) {
          order.insert(order.begin() + l, cure);
        } else if (l == (int)order.size() || order[l] != cure) {
          win = 0;
          break;
        }
        ++l;
      }
    }

    if (win) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
