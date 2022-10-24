#include <bits/stdc++.h>

using namespace std;

struct Drank {
  int p, m, t;
};

struct Sick {
  int p, t;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);

  int n, m, d, s;
  cin >> n >> m >> d >> s;

  Drank drinks[d];

  for (int i{0}; i < d; ++i) {
    cin >> drinks[i].p >> drinks[i].m >> drinks[i].t;
  }

  Sick sicks[s];
  for (int i{0}; i < s; ++i) {
    cin >> sicks[i].p >> sicks[i].t;
  }

  bool bad[m];
  for (int i{0}; i < m; ++i) {
    bad[i] = 1;
    for (int j{0};j<s;++j) {
      bool drank=0;
      bool drankafter=0;
      for (int k{0};k<d;++k){
        if (drinks[k].p == sicks[j].p && drinks[k].m == i + 1) {
          drank=1;
          if (drinks[k].t >= sicks[j].t) {
          } else {
            drankafter = 1;
            break;
          }
        }
      }
      if (drank == 0 || drankafter == 0) {
        bad[i]=0;
      }
      if (!bad[i]) {
        break;
      }
    }
  }

  int ans{0};
  for (int i{0}; i < m; ++i) {
    if (bad[i]) {
      set<int> s;
      for (int j{0}; j < d; ++j) {
        if (drinks[j].m == i + 1) {
          s.insert(drinks[j].p);
        }
      }
      ans = max(ans,(int)s.size());
    }
  }

  cout << ans;

  return 0;
}
