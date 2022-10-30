#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n;
  cin >> x >> n;

  set<pair<ll,pair<ll,ll>>>s;
  set<pair<ll,ll>>s2;
  s.insert({x,{x,0LL}});
  s2.insert({x,0LL});
  while (n--) {
    ll y;
    cin >> y;
    auto query = s2.lower_bound({y, LLONG_MIN});
    pair<ll,ll> actual = *query;
    s2.erase(query);
    s2.insert({actual.first,y});
    s2.insert({y,actual.second});
    s.erase({actual.first-actual.second,actual});
    s.insert({y-actual.second,{y,actual.second}});
    s.insert({actual.first-y,{actual.first,y}});
    cout << (s.rbegin())->first << "\n";
  }

  return 0;
}
