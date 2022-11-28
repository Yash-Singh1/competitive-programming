// TLE, need another strategy

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);

  int n, b;
  cin >> n >> b;

  if (n < 3) {
    while (b--) cout << 1 << "\n";
    return 0;
  }

  vector<pair<int,int>> tiles(n);
  for (int i{0}; i < n; ++i) {
    cin >> tiles[i].first;
    tiles[i].second = i;
  }
  sort(tiles.begin(), tiles.end());

  set<pair<int,int>> gaps;
  map<int,int> gapsz{{n-2, 1}};
  gaps.insert({1, n-2});
  map<int,int> step2gap;

  pair<int,int> search;
  pair<int,int> val;
  set<pair<int,int>>::iterator query;
  for (int i{0}; i < n; ++i) {
    if (tiles[i].second == 0 || tiles[i].second == n-1) continue;
    search = {tiles[i].second, INT_MIN};
    query = upper_bound(gaps.begin(), gaps.end(), search);
    if (query->first != tiles[i].second) query = prev(query);
    if (query->first <= tiles[i].second && query->second >= tiles[i].second) {
      val = *query;
      gaps.erase(val);
      --gapsz[val.second - val.first + 1];
      if (gapsz[val.second - val.first + 1] == 0) gapsz.erase(val.second - val.first + 1);
      if (val.first < tiles[i].second) {
        gaps.insert({val.first, tiles[i].second - 1});
        ++gapsz[tiles[i].second - val.first];
      }
      if (val.second > tiles[i].second) {
        gaps.insert({tiles[i].second + 1, val.second});
        ++gapsz[val.second - tiles[i].second];
      }
    }
    // if (query->first == query->second) {
    //   --gapsz[1];
    //   if (gapsz[1] == 0) gapsz.erase(1);
    //   gaps.erase(query);
    // } else if (query->second == tiles[i].second) {
    //   val = *query;
    //   gaps.erase(val);
    //   --gapsz[val.second - val.first + 1];
    //   if (gapsz[val.second - val.first + 1] == 0) gapsz.erase(val.second - val.first + 1);
    //   gaps.insert({val.first, val.second - 1});
    //   ++gapsz[val.second - val.first];
    // } else if (query->first == tiles[i].second) {
    //   val = *query;
    //   gaps.erase(val);
    //   --gapsz[val.second - val.first + 1];
    //   if (gapsz[val.second - val.first + 1] == 0) gapsz.erase(val.second - val.first + 1);
    //   gaps.insert({val.first+1, val.second});
    //   ++gapsz[val.second - val.first];
    // } else if (query->first < tiles[i].second && query->second > tiles[i].second) {
    //   val = *query;
    //   gaps.erase(val);
    //   --gapsz[val.second - val.first + 1];
    //   if (gapsz[val.second - val.first + 1] == 0) gapsz.erase(val.second - val.first + 1);
    //   gaps.insert({val.first, tiles[i].second - 1});
    //   gaps.insert({tiles[i].second + 1, val.second});
    //   ++gapsz[tiles[i].second - val.first];
    //   ++gapsz[val.second - tiles[i].second];
    // }
    if (step2gap.find(gapsz.empty() ? 0 : gapsz.rbegin()->first) == step2gap.end()) {
      step2gap[gapsz.empty() ? 0 : gapsz.rbegin()->first] = tiles[i].first;
    }
  }

  int depth, size;
  for (int i{0}; i < b; ++i) {
    cin >> depth >> size;
    if (size >= n-1) {
      cout << 1 << "\n";
    } else {
      cout << ((prev(step2gap.upper_bound(size-1))->second) <= depth) << "\n";
    }
  }

  return 0;
}
