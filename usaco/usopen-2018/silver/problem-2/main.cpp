#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);

  int n;
  cin >> n;
  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n,greater<int>());

  int gotinline{0};
  for (int i{0}; i < n; ++i) {
    if (gotinline <= a[i]) {
      ++gotinline;
    }
  }

  cout << gotinline << "\n";

  return 0;
}
