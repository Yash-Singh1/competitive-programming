#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(pair<ll,pair<ll,ll>>a,pair<ll,pair<ll,ll>>b) {
  if (a.first == b.first) {
    return a.second.first > b.second.first;
  }
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  pair<ll,pair<ll,ll>> p[n*2];

  for (ll i{0}; i < n; ++i) {
    cin >> p[i*2].first >> p[i*2+1].first;
    p[i*2].second.first=1;
    p[i*2].second.second=i;
    p[i*2+1].second.first=-1;
    p[i*2+1].second.second=i;
  }

  sort(p,p+n*2,cmp);

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (ll i{1}; i < 200001; ++i) {
    pq.push(i);
  }

  ll ans[n];
  ll ovans{0};
  for (int i{0}; i < n * 2; ++i) {
    if (p[i].second.first == -1) {
      pq.push(ans[p[i].second.second]);
    } else {
      ans[p[i].second.second] = pq.top();
      ovans = max(ovans,pq.top());
      pq.pop();
    }
  }

  cout << ovans << "\n";
  for (int i{0}; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
