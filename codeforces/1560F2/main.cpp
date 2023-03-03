#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mn;
vector<int> digits;
ll tenp[10];

int k;

// dp[set of digits used][position of current digit][over]
vector<vector<vector<ll>>> dp(1<<10, vector<vector<ll>>(10, vector<ll>(2, -1)));

ll dfs(int b, int pos, int over, int popcount) {
  if (pos == digits.size()) return 0;
  if (dp[b][pos][over] != -1) return dp[b][pos][over];
  int limit = digits[pos];
  if (over) {
    limit = 0;
  }
  for (int i{limit}; i <= 9; ++i) {
    if (popcount == k && (b&(1<<i))) continue;
    ll res = dfs((b|(1<<i))^(1<<i), pos + 1, over ? over : (i > limit), popcount+((b&(1<<i))?1:0));
    if (res == -2) {
      continue;
    } else {
      return dp[b][pos][over] = i * tenp[digits.size() - pos - 1] + res;
    }
  }
  return dp[b][pos][over] = -2;
}

inline void regenmn() {
  digits.clear();
  digits.reserve(9);
  while (mn) {
    digits.push_back(mn%10);
    mn /= 10;
  }
  reverse(digits.begin(), digits.end());
}

void reset() {
  for (int i{0}; i < (1<<10); ++i) {
    for (int j{0}; j < 10; ++j) {
      for (int k{0}; k < 2; ++k) {
        dp[i][j][k] = -1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  tenp[0] = 1;
  for (int i{1}; i < 10; ++i) {
    tenp[i] = tenp[i - 1] * 10;
  }

  int t;
  cin >> t;
  ll n;
  while (t--) {
    cin >> n >> k;
    mn = n;
    regenmn();
    reset();
    cout << dfs((1<<10)-1, 0, 0, 0) << '\n';
  }

  return 0;
}
