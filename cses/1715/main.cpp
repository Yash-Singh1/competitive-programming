#include <bits/stdc++.h>

using namespace std;

const long long m = 1000000007;

long long bp(long long a, long long b) {
    long long ans{1};
    while (b>0) {
        a %= m;
        if (b%2==1) {
            ans*=a;
            ans%=m;
        }
        b/=2;
        a *= a % m;
    }
    return ans % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n{static_cast<int>(s.size())};
  int a[26];
  for (int i{0}; i < 26; ++i) {
    a[i] = 0;
  }
  for (auto ch: s) {
    ++a[ch - 'a'];
  }
  long long ans{1};
  map<int, int> memo;
  memo[0] = 1;
  for (int i{1}; i <= n; ++i) {
    ans *= i;
    ans %= m;
    // if (i < 20) cout << ans << " " << i << endl;
    memo[i] = ans;
  }
  for (int i{0}; i < 26; ++i) {
    // cout << ans << " " << bp(memo[a[i]], m - 2) << " " << (ans * (bp(memo[a[i]], m - 2))) % m << endl;
    ans = (ans * (bp(memo[a[i]], m - 2))) % m;
    // ans %= m;
  }
  cout << ans;
}
