#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, s;
  cin >> n >>s;
  ll a[n];
  for (ll i{0}; i <n;++i){
    cin >>a[i];
  }
  for(ll i{1};i<n;++i){
    a[i]+=a[i-1];
  }

  ll l{0},r{0};
  ll ans{0};
  while(l<n){
    while(r<n&&a[r]-(l?a[l-1]:0)<=s)++r;
    if (a[r-1]-(l?a[l-1]:0)<=s) ans=max(ans,r-l);
    ++l;
  }
  cout<<ans;

  return 0;
}
