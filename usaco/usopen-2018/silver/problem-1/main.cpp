#include <bits/stdc++.h>

using namespace std;

bool cmp_sec(pair<int,int>a,pair<int,int>b) {
  return a.second<b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);

  int n;
  cin >> n;

  pair<int,int> a[n];
  for (int i{0}; i< n;++i){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a,a+n);
  for (int i{0}; i <n; ++i) {
    a[i].first = i;
  }
  sort(a,a+n,cmp_sec);

  int ans{1};
  for (int i{0}; i < n;  ++i) {
    ans=max(ans,i-a[i].first+1);
  }

  cout << ans;

  return 0;
}
