#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=1000000000+7;

// sums of each y and x
vector<ll> yss[20001], xss[20001];
vector<ll> pyss[20001], pxss[20001];

// total count for ys and xs
ll ys[20001], xs[20001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  ll n;
  cin >>n;

  // for (ll i{0}; i < 20001; ++i) {
  //   yss[i] = 0;
  //   xss[i] = 0;
  //   xs[i]=0;
  //   ys[i]=0;
  // }

  pair<ll,ll>a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    a[i].first+=10000;
    a[i].second+=10000;
    xss[a[i].first].push_back(a[i].second);
    yss[a[i].second].push_back(a[i].first);
    pxss[a[i].first].push_back(a[i].second);
    pyss[a[i].second].push_back(a[i].first);
    ++xs[a[i].first];
    ++ys[a[i].second];
  }

  for (ll i{0}; i < 20001; ++i) {
    sort(xss[i].begin(), xss[i].end());
    sort(yss[i].begin(), yss[i].end());
    sort(pxss[i].begin(), pxss[i].end());
    sort(pyss[i].begin(), pyss[i].end());
    for (ll j{1}; j < pxss[i].size(); ++j) {
      pxss[i][j] = pxss[i][j] + pxss[i][j - 1];
    }
    for (ll j{1}; j < pyss[i].size(); ++j) {
      pyss[i][j] = pyss[i][j] + pyss[i][j - 1];
    }
  }

  ll ans{0};
  for (ll i{0}; i<n;++i) {
    ll low1{0}, high1{xss[a[i].first].size() - 1};
    ll low2{0}, high2{yss[a[i].second].size()-1};
    ll ans1, ans2;
    while (low1 <= high1) {
      ll mid{(low1 + high1) / 2};
      if (xss[a[i].first][mid] == a[i].second) {
        ans1 = mid;
        break;
      } else if (xss[a[i].first][mid] > a[i].second) {
        high1 = mid - 1;
      } else {
        low1 = mid + 1;
      }
    }
    while (low2 <= high2) {
      ll mid{(low2 + high2) / 2};
      if (yss[a[i].second][mid] == a[i].first) {
        ans2 = mid;
        break;
      } else if (yss[a[i].second][mid] > a[i].first) {
        high2 = mid - 1;
      } else {
        low2 = mid + 1;
      }
    }
    ll xtemp{abs((ans1 == 0 ? 0 : ((ans1 * a[i].second) - pxss[a[i].first][ans1 - 1])) +
      (ans1 == pxss[a[i].first].size() - 1 ? 0 : (pxss[a[i].first][pxss[a[i].first].size() - 1] - pxss[a[i].first][ans1]) - (xs[a[i].first] - ans1 - 1) * a[i].second))%mod};
    ll ytemp{abs((ans2 == 0 ? 0 : ((ans2 * a[i].first) - pyss[a[i].second][ans2 - 1])) +
      (ans2 == pyss[a[i].second].size() - 1 ? 0 : (pyss[a[i].second][pyss[a[i].second].size() - 1] - pyss[a[i].second][ans2]) - (ys[a[i].second] - ans2 - 1) * a[i].first))%mod};
    ans += ((xtemp) * (ytemp)) % mod;
    ans %= mod;
  }

  cout << ans;

  return 0;
}
