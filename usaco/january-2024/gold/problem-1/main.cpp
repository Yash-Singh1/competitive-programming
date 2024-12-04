#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<int,int>,int> piii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  set<int> v;
  set<int> h;
  char c;
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> c >> x;
    if (c == 'V') {
      v.insert(x);
    } else {
      h.insert(x);
    }
  }

  int y, d;
  vector<piii> qs(q);
  for (int i{0}; i < q; ++i) {
    cin >> qs[i].first.first >> qs[i].first.second >> qs[i].second;
  }

  int qi{0};
  while (q--) {
    x = qs[qi].first.first; y = qs[qi].first.second; d = qs[qi].second;
    ++qi;
    auto hfind = h.find(y);
    auto vfind = v.find(x);
    int dir = 0;
    int t = 0;
    if (vfind != v.end() && hfind != h.end()) {
      dir = 0;
    } else if (hfind != h.end()) {
      dir = 1;
    } else {
      assert(vfind != v.end());
      dir = 0;
    }
    // cout << dir << '\n';
    while (d) {
      int nx = 0;
      if (dir == 0) {
        hfind = h.upper_bound(y);
        if (hfind == h.end()) {
          nx = INT_MAX;
        } else {
          nx = *hfind;
        }
      } else {
        vfind = v.upper_bound(x);
        if (vfind == v.end()) {
          nx = INT_MAX;
        } else {
          nx = *vfind;
        }
      }
      if (d >= (nx-(dir==0?y:x))) {
        // cout << qi << ' ' << x << ' ' << y << ' ' << nx << ' ' << (nx-(dir==0?y:x)) << ' ' << dir << '\n';
        t += (nx-(dir==0?y:x));
        d -= (nx-(dir==0?y:x));
        if (dir == 0) {
          y = nx;
        } else {
          x = nx;
        }
        if (t % 2 == 0) {
          dir = 0;
        } else {
          dir = 1;
        }
      } else {
        if (dir == 0) {
          y += d;
        } else {
          x += d;
        }
        d = 0;
      }
    }
    cout << x << ' ' << y << '\n';
  }

  return 0;
}
