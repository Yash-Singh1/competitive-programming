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
      // NOTE: Uses Running Sum. For simplicity imagine that you are in a prefix sum with e being the original ans sum being the sum till now.
      ans += m[sum - x];
      m[sum]++;
  }
  // The map contains the number of times a certain sum is filled up till.
  // So if I have 7 0 3, with x = 10, the number of times it gets filled up is 2.
  // Whenever ans is incremented, it gets incremented by the number of times the rest of the sum needed to fill is filled up already.
  // Another example is 8 3 with x = 3. The prefix sum is 8 11. Since the sum of the subarray [1, 1] is 3. As expected 11 - 8 will give us the expected 3.
  std::cout << ans;
}
