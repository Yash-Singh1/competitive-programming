#include <bits/stdc++.h>

using namespace std;

int n, timemax;
int d[100000];

bool validate(int k) {
  priority_queue<int> stage;
  for (int i{0}; i < k; ++i) {
    stage.push(-d[i]);
  }
  priority_queue<int> waiting;
  for (int i{k}; i < n; ++i) {
    waiting.push(-i);
  }
  int fst{-stage.top()};
  int lst{-stage.top()};
  while (!stage.empty() || !waiting.empty()) {
    lst = -stage.top();
    stage.pop();
    if (!waiting.empty()) {
      // cout << k << " " << lst << " " << d[-waiting.top()] << " " << waiting.top() << "\n";
      stage.push(-d[-waiting.top()] - lst);
      waiting.pop();
    }
  }
  // cout << lst << " " << fst << " " << k << "\n";
  return lst <= timemax;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowdance.in", "r", stdin);
  freopen("cowdance.out", "w", stdout);

  cin >> n >> timemax;

  for (int i{0}; i < n; ++i) {
    cin >> d[i];
  }

  int l{1}, h{n};
  int ans;
  while (l <= h) {
    int mid{(h + l) / 2};
    if (validate(mid)) {
      h = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}
