class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
      vector<pair<int,int>> g[n];
      for (auto &e: roads) {
        --e[0];
        --e[1];
        g[e[0]].push_back({e[1], e[2]});
        g[e[1]].push_back({e[0], e[2]});
      }
      bool visited[n];
      for (int i{0}; i < n; ++i) visited[i] = 0;
      int ans{INT_MAX};
      stack<int> s;
      s.push(0);
      while (!s.empty()) {
        int stop{s.top()};
        s.pop();
        if (visited[stop]) continue;
        visited[stop] = 1;
        for (auto &ne: g[stop]) {
          if (!visited[ne.first]) {
            ans = min(ne.second, ans);
            s.push(ne.first);
          }
        }
      }
      return ans;
    }
};
