// position locked cows
// if 1 in social hierarchy
//  - position social hierarchy from left
// else
//  - 1 is the first avaliable position

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("milkorder.in", "r", stdin);
  freopen("milkorder.out", "w", stdout);

  int n, m, k;
	cin >> n >> m >> k;
  bool onesocial{0};
  int hierarchy[m];
  for (int i{0}; i < m; ++i) {
    cin >> hierarchy[i];
    --hierarchy[i];
    if (hierarchy[i] == 0) {
      onesocial = 1;
    }
  }

  int ordering[n];
  for (int i{0}; i < n; ++i) {
    ordering[i] = -1;
  }

  int x, y;
  bool placed[n];
  int pos[n];
  for (int i{0}; i < n; ++i) {
    placed[i] = 0;
    pos[i] = -1;
  }
  for (int i{0}; i < k; ++i) {
    cin >> x >> y;
    ordering[y-1] = x-1;
    pos[x-1] = y-1;
    placed[x-1] = 1;
    if (x-1 == 0) {
      cout << y << "\n";
      return 0;
    }
  }

  // if (onesocial) {
    // iterate through social hierarchy
    // if already placed, wait for placement
    // else greedily place hierarchy
    int socpos{0};
    for (int i{0}; i < n; ++i) {
      if (socpos >= m && ordering[i] == -1) {
        ordering[i] = 0;
        break;
      }
      if (ordering[i] == hierarchy[socpos]) {
        ++socpos;
      } else if (ordering[i] == -1) {
        if (hierarchy[socpos] == 0) {
          ordering[i] = 0;
          break;
        }
        // cout << i << " " << ordering[i] << " " << pos[hierarchy[socpos]] << " " << hierarchy[socpos] << " " << placed[hierarchy[socpos]] << "\n";
        int spaces{-1};
        for (int j{socpos}; j < m; ++j) {
          // cout << i << " " << j << " " << placed[hierarchy[j]] << "\n";
          if (placed[hierarchy[j]]) {
            spaces = 0;
            for (int k{i}; k < pos[hierarchy[j]]; ++k) {
              if (ordering[k] == -1) {
                ++spaces;
              }
            }
            spaces -= j - socpos;
            break;
          }
        }
        if ((!placed[hierarchy[socpos]] && spaces == 0) || onesocial) {
          ordering[i] = hierarchy[socpos];
          placed[hierarchy[socpos]] = 0;
          ++socpos;
        } else {
          ordering[i] = 0;
          break;
        }
      }
    }
    for (int i{0}; i < n; ++i) {
      if (ordering[i] == 0) {
        cout << i + 1 << "\n";
        return 0;
      }
    }
  // }

  return 0;
}
