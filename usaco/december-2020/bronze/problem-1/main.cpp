#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // A, B, C, A+B, B+C, C+A, and A+B+C
  int a[7];
  priority_queue<int> pq;
  for (int i{0}; i < 7; ++i) {
    cin >> a[i];
    pq.push(a[i]);
  }
  int mx{pq.top()};
  pq.pop();
  pq.pop();
  pq.pop();
  int sm{0};
  priority_queue<int> pq2;
  for (int i{0}; i < 4; ++i) {
    sm += pq.top();
    pq2.push(pq.top() * -1);
    pq.pop();
  }
  int notit{mx - sm};
  bool nothere{false};
  int j{0};
  for (int i{0}; i < 4; ++i) {
    int nx{pq2.top()};
    pq2.pop();
    if (nx != notit || nothere) {
      ++j;
      cout << -nx << (j == 3 ? "" : " ");
    } else if (nx == notit) {
      nothere =true;
    }
  }
}
