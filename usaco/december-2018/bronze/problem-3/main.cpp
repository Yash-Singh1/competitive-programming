#include <bits/stdc++.h>

using namespace std;

set<int> combinations(int tot, vector<int> a, vector<int> b, int cur) {
  set<int> ans;
  if (tot == 4) {
    ans.insert(cur);
    return ans;
  }
  vector<int> *a1 = &a;
  vector<int> *b1 = &b;
  if (tot % 2 == 1) {
    b1 = &a;
    a1 = &b;
  }
  for (int i{0}; i < (*a1).size(); ++i) {
    if ((*a1)[i] != -1) {
      int s{(*a1)[i]};
      (*a1)[i] = -1;
      b1->push_back(s);
      // ans.merge(combinations(tot + 1, a, b, cur + (s * (tot % 2 == 1 ? 1 : -1))));
      set<int> combs{combinations(tot + 1, a, b, cur + (s * (tot % 2 == 1 ? 1 : -1)))};
      ans.insert(combs.begin(), combs.end());
      b1->pop_back();
      (*a1)[i] = s;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);

  vector<int> a(10);
  for (int i{0}; i < 10; ++i) {
    cin >> a[i];
  }
  vector<int> b(10);
  for (int i{0}; i < 10; ++i) {
    cin >> b[i];
  }
  set<int> combs{combinations(0, a, b, 1000)};
  cout << combs.size() << "\n";

  return 0;
}
