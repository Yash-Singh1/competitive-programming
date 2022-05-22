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
  int a[n];
  for (int i{0}; i < n; ++i) {
      cin >> a[i];
  }
  ++q;
  while (--q) {
      int l, r;
      cin >> l >> r;
      int sum{0};
      for (int i{l}; i < r; ++i) {
          sum += a[i];
      }
      std::cout << sum << endl;
  }
}
