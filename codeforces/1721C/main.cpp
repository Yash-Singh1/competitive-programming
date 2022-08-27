#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;

  while (--t) {
    int n;
    cin >> n;
    int a[n];
    for (int i{0}; i < n; ++i) {
        cin >> a[i];
    }
    int b[n];
    for (int i{0}; i < n; ++i) {
        cin >> b[i];
    }
    priority_queue<int> pq;
    for (int i{0}; i < n; ++i) {
        pq.push(b[i] * -1);
    }
    for (int i{0}; i < n; ++i) {
        int back{pq.top()};
        // while (back < a[i]) {
        //     pq.pop();
        //     back = pq.top();
        // }
        cout << back - a[i] << " ";
    }
    cout << endl;
    priority_queue<int> pq2;
    for (int i{0}; i < n; ++i) {
        pq2.push(b[i]);
    }
    for (int i{n - 1}; i >= 0; --i) {
        cout << pq2.top() - a[i] << " ";
        pq2.pop();
    }
    cout << endl;
  }

  return 0;
}
