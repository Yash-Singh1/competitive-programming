vector<int> dist(n, INT_MAX);
dist[s] = 0;

deque<int> q;
q.push_front(s);

while (!q.empty()) {
  int u = q.front();
  q.pop_front();
  for (auto &ne: g[u]) {
    if (dist[u] + ne.second < dist[ne.first]) {
      dist[ne.first] = dist[u] + ne.second;
      if (ne.second == 1) {
        q.push_back(ne.first);
      } else {
        q.push_back(ne.second);
      }
    }
  }
}

for (int i{0}; i < n; ++i) cout << dist[i] << " ";
cout << "\n";
