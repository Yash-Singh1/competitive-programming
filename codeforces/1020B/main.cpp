// DFS over each component and run the floyd algorithm
// anything in a cycle is the node itself
// anything not in a cycle is the start of the cycle

#include <bits/stdc++.h>

using namespace std;

// bool visited[1000];
int g[1000];
int ans[1000];

void dfs(int i) {
  if (ans[g[i]] == -1) {
    dfs(g[i]);
    ans[i] = ans[g[i]];
  } else {
    ans[i] = ans[g[i]];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i{0}; i < n; ++i) {
    // visited[i] = 0;
    // cycle[i] = 0;
    ans[i] = -1;
  }
  for (int i{0}; i < n; ++i) {
    cin >> g[i];
    --g[i];
  }

  for (int i{0}; i < n; ++i) {
    if (ans[i] != -1) continue;
    int t{g[i]}, h{g[g[i]]};
    while (t != h) {
      t = g[t];
      h = g[g[h]];
    }
    h = i;
    while (t != h) {
      t = g[t];
      h = g[h];
    }
    ans[t] = t;
    while (t != h) {
      t = g[t];
      ans[t] = t;
    }
  }

  for (int i{0}; i < n; ++i) {
    if (ans[i] == -1) {
      dfs(i);
    }
  }

  for (int i{0}; i < n; ++i) {
    cout << ans[i]+1 << " ";
  }
  cout << "\n";

  return 0;
}
