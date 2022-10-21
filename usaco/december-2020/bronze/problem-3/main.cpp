#include <bits/stdc++.h>

using namespace std;

struct Cow {
  int x, y;
  int id;
  // this is an x for E and a y for N
  // int m_dist;
  Cow(int _x, int _y, int _id): x{_x}, y{_y}, id{_id} {}
};

bool sort_x(Cow a, Cow b) {
  return a.x < b.x;
}

bool sort_y(Cow a, Cow b) {
  return a.y < b.y;
}

bool sort_id(Cow a, Cow b) {
  return a.id < b.id;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Cow> cowsr;
  vector<Cow> cowsup;

  int cowrc{0}, cowupc{0};
  int cows[n];

  for (int i{0}; i < n; ++i) {
    char dirc;
    cin >> dirc;
    int x, y;
    cin >> x >> y;
    if (dirc == 'E') {
      cowsr.push_back(Cow(x, y, i));
      cows[i] = INT_MAX;
      ++cowrc;
    } else {
      cowsup.push_back(Cow(x, y, i));
      cows[i] = INT_MAX;
      ++cowupc;
    }
  }

  sort(cowsup.begin(), cowsup.end(), sort_x);
  sort(cowsr.begin(), cowsr.end(), sort_y);

  for (int i{0}; i < cowrc; ++i) {
    for (int j{0}; j < cowupc; ++j) {
      if (cowsup[j].x > cowsr[i].x && cowsup[j].y < cowsr[i].y && (cows[cowsup[j].id] == INT_MAX)) {
        if (cowsup[j].x - cowsr[i].x > cowsr[i].y - cowsup[j].y) {
          cows[cowsr[i].id] = cowsup[j].x - cowsr[i].x;
          break;
        } else if (cowsr[i].y - cowsup[j].y > cowsup[j].x - cowsr[i].x) {
          cows[cowsup[j].id] = cowsr[i].y - cowsup[j].y;
        }
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    if (cows[i] == INT_MAX) {
      cout << "Infinity\n";
    } else {
      cout << cows[i] << "\n";
    }
  }

  return 0;
}
