#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  string s;
  cin >> n >> s >> q;

  while (q--) {
    ll repaints;
    char fav;
    cin >> repaints >> fav;

    vector<pair<ll,ll>> inarow;
    for (ll i{0}; i < n; ++i) {
      if (s[i] == fav) {
        ll j{i};
        while (j < n && s[j] == s[i]) {
          ++j;
        }
        inarow.push_back({i,j});
        i = j;
      }
    }
    ll ans{0};
    for (auto &inarowpair: inarow) {
      ll l{inarowpair.first},r{inarowpair.second};
      ll repaintshold{repaints};
      while (repaintshold > 0 && (l > 0 || r <= n - 1)) {
        if (l > 0) {
          --l;
        } else if (r <= n - 1) {
          ++r;
        }
        --repaintshold;
        while (l != inarowpair.first && l > 0 && s[l] == fav) {
          --l;
        }
        while (r != inarowpair.second && r < n - 1 && s[r] == fav) {
          ++r;
        }
      }
      while (l != inarowpair.first && l > 0 && s[l] == fav) {
        --l;
      }
      while (r != inarowpair.second && r <= n - 1 && s[r] == fav) {
        ++r;
      }
      --r;
      repaintshold = repaints;
      ll l2{inarowpair.first},r2{inarowpair.second};
      while (repaintshold > 0 && (l2 > 0 || r2 <= n - 1)) {
        if (r2 <= n - 1) {
          ++r2;
        } else if (l2 > 0) {
          --l2;
        }
        --repaintshold;
        while (l2 != inarowpair.first && l2 > 0 && s[l2] == fav) {
          --l2;
        }
        while (r2 != inarowpair.second && r2 < n - 1 && s[r2] == fav) {
          ++r2;
        }
      }
      while (l2 != inarowpair.first && l2 > 0 && s[l2] == fav) {
        --l2;
      }
      while (r2 != inarowpair.second && r2 <= n - 1 && s[r2] == fav) {
        ++r2;
      }
      ans = max(ans, max(r - l, r2 - l2));
      cout << inarowpair.first << " " << inarowpair.second << " " << l << " " << r << " " << r - l << "\n";
      cout << inarowpair.first << " " << inarowpair.second << " " << l2 << " " << r2 << " " << r2 - l2 << "\n";
    }
    cout << max(ans, min(n, repaints)) << "\n"; 
  }

  return 0;
}
