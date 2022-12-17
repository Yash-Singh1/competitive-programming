#include <bits/stdc++.h>

using namespace std;

int cycle[100000];
bool visited[100000];
int g[100000];
bool cycling{0};

void dfs(int i) {
  if (cycle[i] == 1) return;
  if (visited[i] && cycle[i] != 0) {
    cycle[i] = 1;
    cycling = 1;
    return;
  }
  visited[i] = 1;
  dfs(g[i]);
  if (cycle[i] == 1) {
    cycling = 0;
  } else {
    if (cycling) {
      cycle[i] = 1;
    } else {
      cycle[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  int n;
  cin >> n;
  for (int i{0}; i < n; ++i) {
    cin >> g[i];
    cycle[i] = -1;
    visited[i] = 0;
    --g[i];
  }

  for (int i{0}; i < n; ++i) {
    if (visited[i]) continue;
    cycling = 0;
    dfs(i);
  }

  int tot{0};
  for (int i{0}; i < n; ++i) {
    if (cycle[i] == 1) ++tot;
  }
  cout << tot << "\n";

  return 0;
}
