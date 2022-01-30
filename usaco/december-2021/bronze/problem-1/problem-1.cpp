#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n {0};
  std::string s;
  cin >> n >> s;
  unsigned long long ans {0};
  for (int i{0}; i < n; ++i)
  {
    int right {0};
    int left {0};
    while (i - left - 1 >= 0 && s[i - left - 1] != s[i]) ++left;
    while (i + right + 1 < n && s[i + right + 1] != s[i]) ++right;
    if (right + left + 1 < 3) continue;
    ans += right * left;
    if (right > 1) ans += right - 1;
    if (left > 1) ans += left - 1;
  }
  std::cout << ans;
}
