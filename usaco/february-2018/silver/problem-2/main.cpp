#include <bits/stdc++.h>

using namespace std;

int n, b;
int a[250];
pair<int,int> boo[250];
int mn{INT_MAX};
bool done[250][250];

void search(int i, int boot) {
  if (done[i][boot]) return;
  done[i][boot] = 1;
  if (i == n-1) {
    mn = min(mn, boot);
    return;
  }
  for (int j{i+1}; j < n && j <= i+boo[boot].second; ++j) {
    if (a[j] <= boo[boot].first) {
      search(j, boot);
    }
  }
  for (int j{boot+1}; j < b; ++j) {
    if (a[i] <= boo[j].first) {
      search(i, j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);

  cin >> n >> b;

  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  for (int i=0; i < b; ++i) {
    cin >> boo[i].first >> boo[i].second;
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < b; ++j) {
      done[i][j] = 0;
    }
  }

  search(0, 0);
  cout << mn << "\n";

  return 0;
}
