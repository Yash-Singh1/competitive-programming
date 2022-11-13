// Passes Subtasks 1 & 2 only, because its greedy and takes O(n^2)

#include <bits/stdc++.h>

using namespace std;

bool cmp1(pair<long double,long double> a, pair<long double,long double> b) {
  return a.first > b.first;
}

bool cmp2(pair<long double,long double> a, pair<long double,long double> b) {
  return a.second > b.second;
}

int main() {
  int n;
  cin >> n;

  pair<long double,long double> a[n], b[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    --a[i].first;
    --a[i].second;
    b[i] = a[i];
  }
  sort(a,a+n,cmp1);
  sort(b,b+n,cmp2);

  for (int i{1}; i < n; ++i) {
    a[i].first += a[i-1].first;
    b[i].second += b[i-1].second;
  }

  long double ans{0};
  for (int i{0}; i <= n; ++i) {
    for (int j{0}; j <= n; ++j) {
      ans = max(ans, min((i==0?0:a[i-1].first) - j, (j==0?0:b[j-1].second) - i));
    }
  }

  printf("%.4lf\n",(double)ans);

  return 0;
}
