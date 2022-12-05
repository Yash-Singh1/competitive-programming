#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("family.in", "r", stdin);
  freopen("family.out", "w", stdout);

  int n;
  string a, b;
  cin >> n >> a >> b;

  map<string, string> m;

  string x, y;
  for (int i{0}; i < n; ++i) {
    cin >> x >> y;
    m[y] = x;
  }

  set<pair<string,int>> visa, visb;
  visa.insert({a, 0});

  string cur{a};
  int dist{0};
  while (m.find(cur) != m.end()) {
    cur = m[cur];
    ++dist;
    visa.insert({cur, dist});
  }

  string cure = b;
  int diste = 0;
  while (m.find(cure) != m.end()) {
    cure = m[cure];
    ++diste;
    visb.insert({cure, diste});
  }

  // cout << dist << " " << diste << "\n";
  if (cure != cur) {
    cout << "NOT RELATED\n";
    return 0;
  } else {
    if (diste > dist) {
      string safe{a};
      a = b;
      b = safe;
      visa = visb;
    }
  }
  auto query = visa.lower_bound({b, INT_MIN});
  if (query != visa.end() && query->first == b) {
    cout << b << " is the ";
    for (int i{0}; i < query->second - 2; ++i) {
      cout << "great-";
    }
    if (query->second >= 2) {
      cout << "grand-";
    }
    cout << "mother of " << a << "\n";
    return 0;
  }
  cur = b;
  dist = 0;
  while (m.find(cur) != m.end()) {
    cur = m[cur];
    ++dist;
    query = visa.lower_bound({cur, INT_MIN});
    if (query != visa.end() && query->first == cur) {
      if (query->second == dist) {
        if (dist == 1) {
          cout << "SIBLINGS\n";
        } else {
          cout << "COUSINS\n";
        }
      } else if (dist == 1) {
        cout << b << " is the ";
        for (int i{dist+1}; i < query->second; ++i) {
          cout << "great-";
        }
        cout << "aunt of " << a << "\n";
      } else {
        cout << "COUSINS" << "\n";
      }
      return 0;
    }
  }

  cout << "NOT RELATED\n";

  return 0;
}
