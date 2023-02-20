/*
ID: saiansh1
LANG: C++
TASK: lamps
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lamps.in", "r", stdin);
  freopen("lamps.out", "w", stdout);

  int n, c;
  cin >> n >> c;
  bitset<100> oner, zerr;
  int x;
  cin >> x;
  while (x != -1) {
    --x;
    oner.flip(n-x-1);
    cin >> x;
  }
  cin >> x;
  while (x != -1) {
    --x;
    zerr.flip(n-x-1);
    cin >> x;
  }
  bitset<100> even, odd, three;
  for (int i{0}; i < n; i += 2) {
    even.flip(n-i-1);
  }
  for (int i{1}; i < n; i += 2) {
    odd.flip(n-i-1);
  }
  for (int i{0}; i < n; i += 3) {
    three.flip(n-i-1);
  }

  unordered_set<bitset<100>> ans;
  map<int,unordered_set<bitset<100>>> vis;
  vis[0].insert(~bitset<100>());
  queue<pair<bitset<100>,int>> q;
  q.push({~bitset<100>(), 0});
  while (q.size()) {
    bitset<100> u = q.front().first;
    int d = q.front().second;
    q.pop();
    if (d == c) {
      if ((u & zerr).count() == 0 && ((~u) & oner).count() == 0) {
        ans.insert(u);
      }
    } else {
      u ^= even;
      if (vis[d+1].find(u) == vis[d+1].end()) {
        vis[d+1].insert(u);
        q.push({u, d + 1});
      }
      u ^= even;
      u ^= odd;
      if (vis[d+1].find(u) == vis[d+1].end()) {
        vis[d+1].insert(u);
        q.push({u, d + 1});
      }
      u ^= odd;
      u ^= three;
      if (vis[d+1].find(u) == vis[d+1].end()) {
        vis[d+1].insert(u);
        q.push({u, d + 1});
      }
      u ^= three;
      u = ~u;
      if (vis[d+1].find(u) == vis[d+1].end()) {
        vis[d+1].insert(u);
        q.push({u, d + 1});
      }
    }
  }

  vector<string> anse(ans.size());
  auto it = ans.begin();
  for (int j{0}; j < (int)ans.size(); ++j) {
    for (int i{0}; i < n; ++i) {
      if ((*it).test(n-i-1)) {
        anse[j] += '1';
      } else {
        anse[j] += '0';
      }
    }
    it = next(it);
  }
  sort(anse.begin(), anse.end());

  for (auto &ch: anse) {
    cout << ch << "\n";
  }

  if (!anse.size()) {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}
