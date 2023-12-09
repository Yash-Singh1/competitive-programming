#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pii> points(n+2);

  cin >> points[0].first >> points[0].second >> points[n+1].first >> points[n+1].second;

  vector<int> xs, ys;
  xs.reserve(n+2);
  ys.reserve(n+2);
  for (int i{0}; i < n; ++i) {
    cin >> points[i+1].first >> points[i+1].second;
  }
  for (int i{0}; i < n+2; ++i) {
    xs.push_back(points[i].first);
    ys.push_back(points[i].second);
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  unordered_map<int,int> xm, ym;
  for (int i{0}; i < xs.size(); ++i) {
    xm[xs[i]] = i;
  }
  for (int i{0}; i < ys.size(); ++i) {
    ym[ys[i]] = i;
  }

  vector<vector<int>> alongx(xs.size()), alongy(ys.size());
  for (int i{0}; i < n+2; ++i) {
    points[i] = {xm[points[i].first], ym[points[i].second]};
    alongx[points[i].first].push_back(i);
    alongy[points[i].second].push_back(i);
  }

  vector<vector<int>> dist(n+2, vector<int>(4, INT_MAX));
  queue<pii> q;
  for (int i{0}; i < 4; ++i) {
    dist[0][i] = 0;
    q.push({0, i});
  }
  while (q.size()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    int res;
    if ((res = lower_bound(alongy[points[u].second].begin(), alongy[points[u].second].end(), u) - alongy[points[u].second].begin()) != alongy[points[u].second].size()) {
      if (d == 0 && res + 1 < alongy[points[u].second].size() && dist[alongy[points[u].second][res+1]][d] > dist[u][d]) {
        dist[alongy[points[u].second][res+1]][d] = dist[u][d];
        q.push({alongy[points[u].second][res+1], d});
      }
      else if (d == 1 || d == 3) {
        if (res + 1 < alongy[points[u].second].size() && dist[alongy[points[u].second][res+1]][0] > dist[u][d] + 1) {
          dist[alongy[points[u].second][res+1]][0] = dist[u][d] + 1;
          q.push({alongy[points[u].second][res+1], 0});
        }
        if (res && dist[alongy[points[u].second][res-1]][2] > dist[u][d] + 1) {
          dist[alongy[points[u].second][res-1]][2] = dist[u][d] + 1;
          q.push({alongy[points[u].second][res-1], 2});
        }
      }
      else if (d == 2 && res && dist[alongy[points[u].second][res-1]][d] > dist[u][d]) {
        dist[alongy[points[u].second][res-1]][d] = dist[u][d];
        q.push({alongy[points[u].second][res-1], d});
      }
    }
    if ((res = lower_bound(alongx[points[u].first].begin(), alongx[points[u].first].end(), u) - alongx[points[u].first].begin()) != alongx[points[u].first].size()) {
      if (d == 1 && res + 1 < alongx[points[u].first].size() && dist[alongx[points[u].first][res+1]][d] > dist[u][d]) {
        dist[alongx[points[u].first][res+1]][d] = dist[u][d];
        q.push({alongx[points[u].first][res+1], d});
      } else if (d == 0 || d == 2) {
        if (res + 1 < alongx[points[u].first].size() && dist[alongx[points[u].first][res+1]][1] > dist[u][d] + 1) {
          dist[alongx[points[u].first][res+1]][1] = dist[u][d] + 1;
          q.push({alongx[points[u].first][res+1], 1});
        }
        if (res && dist[alongx[points[u].first][res-1]][3] > dist[u][d] + 1) {
          dist[alongx[points[u].first][res-1]][3] = dist[u][d] + 1;
          q.push({alongx[points[u].first][res-1], 3});
        }
      } else if (d == 3 && res && dist[alongx[points[u].first][res-1]][d] > dist[u][d]) {
        dist[alongx[points[u].first][res-1]][d] = dist[u][d];
        q.push({alongx[points[u].first][res-1], d});
      }
    }
  }

  int mn{INT_MAX};
  for (auto &dd: dist[n+1]) mn = min(mn, dd);
  cout << (mn==INT_MAX?-1:mn) << '\n';

  return 0;
}
