#include <iostream>
#include <ios>
#include <map>
#define endl "\n"

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, x;
  cin >> n >> x;
  long long a[n];
  for (long long i{0}; i < n; ++i) {
      cin >> a[i];
  }
  long long sum{0};
  long long ans{0};
  std::map<long long, long long> m;
  m[0] = 1;
  for (auto e: a) {
      sum += e;
      ans += m[sum - x];
      m[sum]++;
  }
  std::cout << ans;
}
