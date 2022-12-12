/*
ID: saiansh1
LANG: C++
TASK: hamming
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("hamming.in", "r", stdin);
  freopen("hamming.out", "w", stdout);

  int n, b, d;
  cin >> n >> b >> d;
  
  vector<int> ans;
  for (int i{0}; i < (1<<b) && (int)ans.size() < n; ++i) {
    bool val{1};
    for (auto &c: ans) {
      if (__builtin_popcount(c^i) < d) {
        val = 0;
        break;
      }
    }
    if (val) {
      ans.push_back(i);
    }
  }

  for (int i{0}; i < (int)ans.size(); ++i) {
    if ((i%10) != 0) {
      cout << " ";
    } else if (i != 0) {
      cout << "\n";
    }
    cout << ans[i];
  }
  cout << "\n";
}
