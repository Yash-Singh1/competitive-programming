#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("pcb.in", "r", stdin);
  // freopen("pcb.out", "w", stdout);

  int n;
  cin >> n;

  vector<pii> cond(n);
  for (int i{0}; i < n; ++i) {
    cin >> cond[i].first >> cond[i].second;
  }

  sort(cond.begin(), cond.end(), greater<pii>());

  vector<int> best;
  for (int i{0}; i < n; ++i) {
    auto it = upper_bound(best.begin(), best.end(), cond[i].second);
    if (it == best.end()) {
      best.push_back(cond[i].second);
    } else {
      best[it - best.begin()] = cond[i].second;
    }
  }

  cout << best.size() << "\n";

  return 0;
}
