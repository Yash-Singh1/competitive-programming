#include <bits/stdc++.h>

using namespace std;

int calc(int x) {
  string s = to_string(x);
  int tot{0};
  for (auto c : s) {
    tot += c - '0';
  }
  return tot % 13;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<pair<int, int>> pq;
  int n, m;
  cin >> n >> m;
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    pq.push({calc(x), x});
  }
  for (int i{0}; i < m; ++i) {
    cout << pq.top().second << '\n';
    pq.pop();
  }
}
