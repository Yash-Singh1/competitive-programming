// dfs over the graph (recursively)
//  - if encountering a node which already has its answer set return, parent will set to that + 1
//  - keep a track of the amount of teles required to reach a certain point
//    - subtract that with the current teles when a cycle is detected because a point is visited
//    - set that as the ans because that is the cycle length
//  - toggle bool representing fact that inside cycle
//  - returning nodes check if their answer has been updated yet
//     - if updated, cycle over, return
//     - else, set value to next node's answer
//  - if currently not in a cycle and recursive dfs is over for children nodes
//     - set answer to child node's answer + 1

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g(200000);
vector<int> ans(200000);
vector<int> visitback(200000);
bool cycling{0};

void dfs(int i, int tot) {
  if (ans[i] != -1) return;
  if (visitback[i] != -1) {
    ans[i] = tot - visitback[i];
    cycling = 1;
    return;
  }
  visitback[i] = tot;
  dfs(g[i], tot + 1);
  if (ans[i] != -1) {
    cycling = 0;
    return;
  }
  ans[i] = cycling ? ans[g[i]] : ans[g[i]] + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{0}; i < n; ++i) {
    cin >> g[i];
    --g[i];
  }

  for (int i{0}; i < n; ++i) {
    ans[i] = -1;
    visitback[i] = -1;
  }

  for (int i{0}; i < n; ++i) dfs(i, 0);
  for (int i{0}; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
