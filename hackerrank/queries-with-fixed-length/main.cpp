vector<int> solve(vector<int> arr, vector<int> queries) {
    int n{(int)arr.size()};
    vector<int> anse(queries.size());
    int curq{0};
    for (auto &q: queries) {
      deque<pair<int,int>> dq;
      for (int i{0}; i < q; ++i) {
        while (dq.size() && dq.back().second < arr[i]) {
            dq.pop_back();
        }
        dq.push_back({i, arr[i]});
      }
      int ans{INT_MAX};
      ans = min(ans, dq.front().second);
      for (int i{0}; i <= n - q - 1; ++i) {
          if (i) {
              if (dq.size() && dq.front().first == i) {
                  dq.pop_front();
              }
              while (dq.size() && dq.back().second < arr[i+q]) {
                  dq.pop_back();
              }
              dq.push_back({i+q, arr[i+q]});
          }
          ans = min(ans, dq.front().second);
      }
      anse[curq] = ans;
      ++curq;
    }
    return anse;
}
