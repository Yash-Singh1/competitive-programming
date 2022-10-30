#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    a[x-1]=i;
  }

  pair<int,int> id[n];
  for (int i{0}; i < n; ++i) {
    cin >> id[i].second;
  }

  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < n; ++j) {
      id[j].first = a[j];
    }
    sort(id,id+n);
  }

  for (int i{0}; i < n; ++i) {
    cout << id[i].second << "\n";
  }

  return 0;
}
