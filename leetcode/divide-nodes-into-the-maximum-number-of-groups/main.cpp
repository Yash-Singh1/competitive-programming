// WA, some sort of off by 1 error or starting point finding error

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
      vector<int> g[n];
      for (auto &e: edges) {
        --e[0]; --e[1];
        g[e[1]].push_back(e[0]);
        g[e[0]].push_back(e[1]);
      }
      int color [n];
      for (int i{0}; i < n; ++i) color[i] = -1;
      int groups{0};
      bool visited[n];
      bool visited2[n];
      for (int i{0}; i < n; ++i) visited[i] = 0;
      for (int j{0}; j < n; ++j) {
        if (visited[j]) continue;
        for (int i{0}; i < n; ++i) visited2[i] = 0;
        stack<int> s;
        s.push(j);
        int mn{INT_MAX}, mni{j};
        while (!s.empty()) {
          int stop{s.top()};
          s.pop();
          if (visited2[stop]) continue;
          visited2[stop] = 1;
          if (g[stop].size() < mn) {
            mn = g[stop].size();
            mni = stop;
          }
          for (auto &ne: g[stop]) {
            if (!visited2[ne]) {
              s.push(ne);
            }
          }
        }
        color[mni] = groups+1;
        ++groups;
        queue<int> q;
        q.push(mni);
        while (!q.empty()) {
          int qtop{q.front()};
          q.pop();
          if (visited[qtop]) continue;
          visited[qtop] = 1;
          bool adoptions = 0;
          for (auto &ne: g[qtop]) {
            if (!visited[ne]) {
              q.push(ne);
              color[ne] = color[qtop] + 1;
              adoptions = 1;
            } else {
              if (abs(color[ne] - color[qtop]) != 1) {
                return -1;
              }
            }
          }
          cout << n << " " << groups << " " << qtop << "\n";
          if (adoptions) {
            groups = max(groups, color[qtop] + 1);
          }
        }
      }
      return groups;
    }
};
