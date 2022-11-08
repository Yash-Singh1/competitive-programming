#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  int algs{0};
  int a[n];
  for (int i{0}; i < n; ++i) {
      cin >> a[i];
  }
  for (int i{0}; i < n; ++i) {
      int min{a[i]};
      int mini{i};
      for (int j{i + 1}; j < n; ++j) {
          if (a[j] < min) {
              min = a[j];
              mini = j;
          }
      }
      int swp{a[i]};
      a[i] = min;
      a[mini] = swp;
      x -= min;
      if (x >= 0) {
          ++algs;
      }
  }
  std::cout << algs;
}
