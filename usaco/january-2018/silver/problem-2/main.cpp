#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool greatercomp(ll a, ll b) {
  return a > b;
}

bool greatercomp2(pair<ll,ll>a,pair<ll,ll>b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first>b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  ll n, m,  r;
  cin >> n >> m >> r;
  
  ll c[n];
  for (ll i=0; i < n; i++) {
    cin >> c[i];
  }
  sort(c,c+n,greatercomp);

  pair<ll,ll> stores[m];
  for (ll i=0; i < m; i++) {
    cin>>stores[i].second>>stores[i].first;
  }
  sort(stores,stores+m,greatercomp2);

  ll money_stores[m];
  money_stores[0]=stores[0].first*stores[0].second;
  for (ll i=1; i < m; i++) {
    money_stores[i]=money_stores[i-1]+(stores[i].first*stores[i].second);
  }

  ll want_stores[m];
  want_stores[0]=stores[0].second;
  for (ll i=1; i < m; i++) {
    want_stores[i]=want_stores[i-1]+stores[i].second;
  }

  ll rentals[r];
  for (ll i=0; i < r; i++) {
    cin>>rentals[i];
  }
  sort(rentals,rentals+r,greatercomp);

  ll ans{0};
  ll rentalintake{0};
  for (ll i{0}; i < n && i < r; ++i) {
    ans+=rentals[i];
    ++rentalintake;
  }
  ll rentalintake2=rentalintake;
  ll rentalstot=ans;

  sort(rentals,rentals+rentalintake);
  ll shop_now{-1};
  ll milkgotcha{0};
  for (ll i{0}; i < n && i < m; ++i) {
    if (i + 1 + rentalintake > n) {
      rentalstot-=rentals[rentalintake2-rentalintake];
      --rentalintake;
    }
    milkgotcha+=c[i];
    while (shop_now + 1 < m && milkgotcha>want_stores[shop_now+1]) {
      ++shop_now;
    }
    ans=max(
      ans,
      rentalstot+
      (shop_now!=-1?money_stores[shop_now]:0)+
      (shop_now+1<m
        ? ((milkgotcha-
              (shop_now==-1
                ?0
                :want_stores[shop_now]))
            *stores[shop_now+1].first)
        :0)
    );

  }

  cout <<ans;



  return 0;
}
