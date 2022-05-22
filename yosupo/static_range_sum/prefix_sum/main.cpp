#include <iostream>
#include <ios>
#define endl "\n"

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  long long a[n];
  cin >> a[0];
  for (int i{1}; i < n; ++i) {
      cin >> a[i];
      a[i] += a[i - 1];
  }
  ++q;
  while (--q) {
      int l, r;
      cin >> l >> r;
      if (l == 0) {
          std::cout << a[r - 1] << endl;
      } else {
          std::cout << (a[r - 1] - a[l - 1]) << endl;
      }
  }
}
