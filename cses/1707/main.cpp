#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> pii;
 
#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
 
  int x, y;
  vector<vector<int>> g(n);
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
 
  // for (int i{0}; i < n; ++i) {
  //   cout << i << ": ";
  //   for (auto &ne: g[i]) {
  //     cout << ne << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
 
  int ans{INT_MAX};
  for (int i{0}; i < n; ++i) {
    queue<pair<int,pii>> q;
    vector<int> dist(n, INT_MAX);
    vector<int> state(n, UNVISITED);
    q.push({i, {-1, 0}});
    // dist[i] = 0;
    while (!q.empty()) {
      pair<int,pii> qtop{q.front()};
      q.pop();
      for (auto &ne: g[qtop.first]) {
        // if (i == 0) cout << ne << "," << dist[ne] << " ";
        if (ne != qtop.second.first) {
          if (ne == i) {
            ans = min(ans, qtop.second.second + 1);
            goto end;
          } else {
            dist[ne] = dist[qtop.first] + 1;
            q.push({ne, {qtop.first, qtop.second.second + 1}});
          }
        }
      }
      // if (i == 0) cout << '\n';
    }
    end: continue;
  }
 
  if (ans == INT_MAX) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }
 
  return 0;
}
