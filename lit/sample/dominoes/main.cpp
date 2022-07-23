#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  priority_queue<int> pq;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
        bool x;
        cin >> x;
        if (x) {
            int far{0};
            while (x && j < m) {
                ++far;
                if (j < m - 1)
                    cin >> x;
                ++j;
            }
            // cout << far << " " << i << " " << j << endl;
            pq.push(far);
        }
    }
  }
  int e{0};
  for (int i{0}; i < k; ++i) {
    e += pq.top();
    pq.pop();
  }
  cout << e;
}
