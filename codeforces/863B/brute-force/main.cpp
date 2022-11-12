#include <bits/stdc++.h>

using namespace std;

int min_rearrangement(set<int> a, vector<pair<int,int>> ans, int n, int tot) {
  if (tot == n) {
    int sm{0};
    int mdiff{0};
    for (auto &part: ans) {
      sm += abs(part.first - part.second);
      mdiff = max(mdiff, abs(part.first - part.second));
    }
    return sm - mdiff;
  }
  int msm{INT_MAX};
  int usingo{*a.begin()};
  a.erase(a.begin());
  for (auto it = a.begin(); it != a.end(); it = next(it)) {
    ans.push_back({usingo,*it});
    a.erase(it);
    msm = min(msm, min_rearrangement(a, ans, n, tot + 1));
    a.insert(ans[ans.size() - 1UL].second);
    ans.pop_back();
  }
  return msm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  set<int> a;
  vector<pair<int,int>> ans;
  int o;
  for (int i{0}; i < n*2; ++i) {
    cin >> o;
    a.insert(o);
  }

  cout << min_rearrangement(a, ans, n, 0) << "\n";

  return 0;
}
