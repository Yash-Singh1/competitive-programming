#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    string s;
    cin >> n >> s;
    map<ll,ll>m{{0,1}};
    ll sm{0},tot{0};
    for (auto ch: s) {
      ll r{ch-'0'};
      sm += r;
      --sm;
      tot+=m[sm];
      ++m[sm];
    }
    cout<<tot<<"\n";
  }

  return 0;
}
