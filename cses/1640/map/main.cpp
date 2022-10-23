#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  unordered_map<int,int>m;

  for (int i{0}; i < n; ++i) {
    int a;
    cin >> a;
    if (m[a]) {
      cout << m[a] << " " << i + 1 << "\n";
      return 0;
    }
    m[x-a] = i + 1;
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
