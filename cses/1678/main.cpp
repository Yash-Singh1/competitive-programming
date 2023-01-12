#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
bool ansf{0};
vector<bool> visited(100000);
vector<bool> onstack(100000);
vector<vector<int>> g(100000);

bool dfs(int u) {
  if (ansf) return 0;
  visited[u] = onstack[u] = 1;
  for (auto &v: g[u]) {
    if (onstack[v]) { // starting cycle
      // cout << v << " " << u << "\n";
      ans.push_back(u + 1);
      onstack[u] = 0;
      onstack[v] = 0;
      return true;
    } else if (!visited[v]) {
      if (dfs(v)) { // continue cycle
        if (onstack[u]) {
          ans.push_back(u + 1);
          onstack[u] = 0;
          return true;
        } else {
          // end cycle
          ans.push_back(u + 1);
          ansf = 1;
          return false;
        }
      }
      if (ansf) return 0;
    }
  }
  onstack[u] = 0;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
  }
  for (int i{0}; !ansf && i < n; ++i) {
    dfs(i);
  }
  end: {
    if (ansf) {
      reverse(ans.begin(), ans.end());
      cout << ans.size()+1 << "\n";
      for (auto &anse: ans) {
        cout << anse << " ";
      }
      cout << ans[0];
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}
