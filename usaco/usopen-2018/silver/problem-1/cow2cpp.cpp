#include <bits/stdc++.h>

using namespace std;

bool sorted(int n, int a[]) {
  int lst{-1};
  for (int i{0}; i < n; ++i) {
    if (a[i] < lst) {
      return false;
    }
    lst = a[i];
  }
  return 1;
}

// int main() {
int cow2cpp() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  for (int i{0};i <n; ++i) {
    cin >> a[i];
  }

  int tot{0};
  while (!sorted(n, a)) {
    ++tot;
    for (int i{0}; i <= n - 2; ++i) {
      if (a[i + 1] < a[i]) {
        int s{a[i]};
        a[i] = a[i + 1];
        a[i + 1] =s;
      }
    }
  }

  cout << tot;

  return 0;
}
