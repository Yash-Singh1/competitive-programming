#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<vector<vector<ll>>>> dp(19, vector<vector<vector<ll>>>(10, vector<vector<ll>>(2, vector<ll>(2, -1))));
ll mx;
vector<ll> ds;

ll dfs(ll pos, ll last, ll under, ll zeroes) {
  if (pos == (ll)ds.size()) return 1;
  if (zeroes == 0 && dp[pos][last][under][zeroes] != -1) return dp[pos][last][under][zeroes];
  ll sm{0}, limit;
  if (under) {
    limit = 9;
  } else {
    limit = ds[pos];
  }
  // cout << pos << " " << limit << " " << zeroes << " " << last << "\n";
  for (ll i{0}; i <= limit; ++i) {
    if (i == last && zeroes == 0) continue;
    sm += dfs(pos + 1, i, (under == 1) ? 1 : (i < limit), ((zeroes == 1) ? (i == 0) : 0));
  }
  return dp[pos][last][under][zeroes] = sm;
}

void regenmx() {
  ds.clear();
  if (!mx) {
    ds.push_back(0); return;
  }
  while (mx) {
    ds.push_back(mx%10);
    mx /= 10;
  }
  reverse(ds.begin(), ds.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;
  cin >> a >> b;

  mx = b;
  regenmx();
  ll first{dfs(0, 0, 0,1)};
  mx = a-1;
  regenmx();
  for (ll i{0}; i < 19; ++i) {
    for (ll j{0}; j < 10; ++j) {
      for (ll k{0}; k < 2; ++k) {
        for (ll l{0}; l < 2; ++l) dp[i][j][k][l] = -1;
      }
    }
  }
  // cout << first << "\n";
  cout << first - (a ? dfs(0,0,0,1) : 0) << "\n";

  return 0;
}
