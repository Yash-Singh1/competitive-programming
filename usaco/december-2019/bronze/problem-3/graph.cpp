// The difference between this solution and the solution for main.cpp is that this one uses graph, while the other one uses complete search.

#include <bits/stdc++.h>

using namespace std;

// Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, and Sue

map<string, int> m{{"Beatrice", 0}, {"Belinda", 1}, {"Bella", 2}, {"Bessie", 3}, {"Betsy", 4}, {"Blue", 5}, {"Buttercup", 6}, {"Sue", 7}};
string back[8] {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> g[8];

  string x, y;
  for (int i{0}; i < n; ++i) {
    cin >> x >> y >> y >> y >> y >> y;
    g[m[x]].push_back(m[y]);
    g[m[y]].push_back(m[x]);
  }

  vector<int> order;
  bool visited[8];
  for (int i{0}; i < 8; ++i) visited[i] = 0;
  for (int i{0}; i < 8; ++i) {
    if (visited[i]) continue;
    if (g[i].size() <= 1) {
      int cur{i};
      while (true) {
        visited[cur] = 1;
        order.push_back(cur);
        bool pick{0};
        for (auto &ne: g[cur]) {
          if (!visited[ne]) {
            cur = ne;
            pick = 1;
            break;
          }
        }
        if (!pick) {
          break;
        }
      }
    }
  }

  for (auto &ordering: order) {
    cout << back[ordering] << "\n";
  }

  return 0;
}
