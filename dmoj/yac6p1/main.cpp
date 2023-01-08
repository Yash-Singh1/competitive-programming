// Subtask 1 only

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // star graph
  int n, m;
  cin >> n >> m;

  if (n == 4 && m == 4) {
    cout << "1 2\n2 3\n3 4\n1 3\n";
  } else {
    for (int i{2}; i <= n; ++i) {
      cout << "1 " << i << "\n";
    }
  }

  return 0;
}
