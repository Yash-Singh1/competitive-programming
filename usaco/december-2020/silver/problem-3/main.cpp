#include <bits/stdc++.h>

using namespace std;

struct Cow {
  int id, x, y;
};

bool sort_y(Cow a, Cow b) {
  return a.y < b.y;
}

bool sort_x(Cow a, Cow b) {
  return a.x < b.x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  Cow up[n], r[n];
  int upl{0}, rl{0};
  char dir;
  for (int i{0}; i < n; ++i) {
    cin >> dir;
    if (dir == 'N') {
      up[upl].id = i;
      cin >> up[upl].x >> up[upl].y;
      ++upl;
    } else {
      r[rl].id = i;
      cin >> r[rl].x >> r[rl].y;
      ++rl;
    }
  }

  sort(up,up+upl, sort_x);
  sort(r, r+rl, sort_y);

  int stopped[n];
  for (int i{0}; i < n; ++i) {
    stopped[i] = -1;
  }

  vector<int> g[n];

  for (int i{0}; i < upl; ++i) {
    for (int j{0}; j < rl; ++j) {
      if (stopped[r[j].id] == -1) {
        if (r[j].x <= up[i].x && up[i].y <= r[j].y) {
          if (up[i].x - r[j].x > r[j].y - up[i].y) {
            stopped[r[j].id] = up[i].id;
            g[up[i].id].push_back(r[j].id);
          } else if (up[i].x - r[j].x < r[j].y - up[i].y) {
            stopped[up[i].id] = r[j].id;
            g[r[j].id].push_back(up[i].id);
            goto death;
          }
        }
      }
    }
    death: continue;
  }

  for (int i{0}; i < n; ++i) {
    stack<int> s;
    s.push(i);
    int tot{0};
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      if (stop != i) {
        ++tot;
      }
      for (auto &ne: g[stop]) {
        s.push(ne);
      }
    }
    cout << tot << "\n";
  }

  return 0;
}
