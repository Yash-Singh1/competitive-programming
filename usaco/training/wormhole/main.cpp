/*
ID: saiansh1
LANG: C++
TASK: wormhole
*/

#include <bits/stdc++.h>

using namespace std;

int g[12];
int n;
pair<int,int> a[12];
bool chosen[12];
vector<pair<int,int>> perm;
map<int,int> m;
bool visited[12];

int tot() {
  if ((int)perm.size() == n/2) {
    for (int i{0}; i < n; ++i) {
      for (int j{0}; j < n; ++j) {
        visited[j] = 0;
      }
      int cur;
      if (i&1) {
        cur = perm[i/2].second;
      } else {
        cur = perm[i/2].first;
      }
      while (true) {
        if (visited[cur]) {
          // for (auto &p: perm) cout << p.first << " " << p.second << "\n";
          // cout << "C" << cur << " " << i << "\n";
          // for (int k{0}; k < n; ++k) {
          //   cout << visited[k] << "\n";
          // }
          // cout << "\n";
          return 1;
        }
        visited[cur] = 1;
        if (g[cur] == -1) break;
        cur = m[g[cur]];
      }
    }
    return 0;
  }
  int sm{0};
  int first{0};
  while (chosen[first]) ++first;
  chosen[first] = 1;
  perm.push_back({first, -1});
  m.insert({first, -1});
  for (int i{first+1}; i < n; ++i) {
    if (chosen[i]) continue;
    chosen[i] = 1;
    perm[perm.size()-1].second = i;
    m[first] = i;
    m[i] = first;
    sm += tot();
    m.erase(i);
    chosen[i] = 0;
  }
  m.erase(first);
  perm.pop_back();
  chosen[first] = 0;
  return sm;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  cin >> n;

  for (int i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    chosen[i] = 0;
  }

  for (int i{0}; i < n; ++i) {
    g[i] = -1;
    for (int j{0}; j < n; ++j) {
      if (i == j) continue;
      if (a[j].second == a[i].second && a[j].first > a[i].first && (g[i] == -1 || a[j].first < a[g[i]].first)) {
        g[i] = j;
      }
    }
    // cout << g[i] << " ";
  }
  // cout << "\n\n";

  cout << tot() << "\n";
}
