#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<vector<int>> dc;
vector<vector<int>> g;
int k;
ll ans = 0;

void dfs(int u, int p) {
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      for (int i{0}; i <= k; ++i) {
        dc[u][i + 1] += dc[v][i];
      }
    }
  }
  dc[u][0] = 1;
  for (auto &v: g[u]) {
    if (v == p) continue;
    for (int i{1}; i <= k; ++i) {
      ans += (dc[v][i - 1]) * (dc[u][k - i] - (i == k ? 0 : dc[v][k - i - 1]));
    }
  }
  ans += dc[u][k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;

  int a, b;
  g.resize(n);
  for (int i{1}; i < n; ++i) {
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dc.assign(n, vector<int>(k+2));
  dfs(0, -1);

  cout << (ans>>1) << "\n";

  return 0;
}
