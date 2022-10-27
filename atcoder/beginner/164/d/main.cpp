#include <bits/stdc++.h>

using namespace std;

int binexp(int base, int pow) {
  base %= 2019;
  int ans{1};
  while (pow > 0) {
    if (pow % 2 != 0) {
      ans *= base;
      ans %= 2019;
      --pow;
    }
    base *= base;
    base %= 2019;
    pow /= 2;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  map<int,int>m{{0,1}};

  int cur{0};
  int pw{1};
  int tot{0};
  for (int i{(int)s.size() - 1}; i >= 0; --i) {
    cur += (s[i] - '0') * pw;
    pw *= 10;
    pw %= 2019;
    cur %= 2019;
    if (m[cur] > 0) {
      // cout << "UP" << " " << cur << " " << m[cur] << "\n";
    }
    tot += m[cur];
    ++m[cur];
  }

  // cout << "MAP" << "\n";
  for(auto it = m.cbegin(); it != m.cend(); ++it)
  {
    // std::cout << it->first << " " << it->second << "\n";
  }

  cout << tot << "\n";

  return 0;
}
