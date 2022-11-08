// go1 is the first time I did it but that was like 6mo back so ima like do this again

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  pair<int,int>a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a,a+n,cmp);

  int lststart{1};
  int count{0};
  for (int i{0}; i < n; ++i) {
    if (a[i].first >= lststart) {
      ++count;
      lststart = a[i].second;
    }
  }

  cout << count << "\n";

  return 0;
}

