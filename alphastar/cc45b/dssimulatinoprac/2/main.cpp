#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pii> room(n);
  room.reserve(n*2);
  for (int i{0}; i < n; ++i) {
    cin >> room[i].first >> room[i].second;
  }
  for (int i{0}; i < n; ++i) {
    room.push_back(room[i]);
  }

  vector<int> dist(n+1);
  dist[0] = 0;
  for (int i{1}; i <= n; ++i) {
    dist[i] = dist[i-1] + (abs(room[i].first - room[i-1].first) + abs(room[i].second - room[i-1].second));
  }

  int mxp{0};
  map<vector<int>,int> mp;
  vector<int> path;

  path.reserve(2*n);
  pii prev, nx;
  for (int k{0}; k < n; ++k) {
    if (k) {
      prev = room[k-1];
    } else {
      prev = room[n-1];
    }
    nx = room[k+1];
    int chx = room[k].first - prev.first;
    int chy = room[k].second - prev.second;
    bool largea = 0;
    if (chx) {
      if (nx.second - room[k].second < 0) {
        largea = 1;
      } else {
        largea = 0;
      }
      if (chx > 0) {
        largea = !largea;
      }
    }
    if (chy) {
      if (nx.first - room[k].first < 0) {
        largea = 0;
      } else {
        largea = 1;
      }
      if (chy > 0) {
        largea = !largea;
      }
    }
    path.push_back(largea);
    path.push_back(abs(nx.first - room[k].first) + abs(nx.second - room[k].second));
  }

  for (int i{0}; i < (int)path.size(); i += 2) {
    for (int j{1}; i + j <= (int)path.size(); j += 2) {
      vector<int> pttemp(j);
      copy(path.begin() + i, path.begin() + i + j, pttemp.begin());
      ++mp[pttemp];
    }
  }

  for (int i{1}; i < n; ++i) {
    int cost{0}, lst{-1};
    for (int j{i+1}; j <= n; ++j) {
      // cout << j << ' ' << (dist[j] - dist[j-1]) << '\n';
      cost += dist[j] - dist[j-1];
      lst = j;
      if (j == n) break;
      if (mp[vector<int>(path.begin() + i*2, path.begin() + j*2 + 1)] == 1) break;
    }
    // cout << i << ' ' << (dist[n] - dist[lst]) << ' ' << (dist[lst]);
    cost += min(dist[n] - dist[lst], dist[lst]);
    // cout << ' ' << cost;
    cost = cost - min(dist[n] - dist[i], dist[i]);
    // cout << ' ' << cost << '\n';
    mxp = max(cost, mxp);
  }

  cout << mxp << '\n';

  return 0;
}
