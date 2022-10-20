#include <bits/stdc++.h>

using namespace std;

struct Log {
  int day;
  int diff;
  string name;
  bool operator<(const Log &p) {
    return day < p.day;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> m;

  Log logs[n];

  for (int i{0}; i<n;++i){
    cin >> logs[i].day >> logs[i].name >> logs[i].diff;
    m[logs[i].name]=7;
  }

  sort(logs, logs + n);

  map<int, int> mf;
  mf[7]=m.size();

  pair<int,int> winner{7,m.size()};

  int changes{0};
  for (int i{0}; i < n; ++i) {
    --mf[m[logs[i].name]];
    if (mf[m[logs[i].name]] == 0) {
      mf.erase(m[logs[i].name]);
    }
    bool singlewinnerpos{m[logs[i].name] == winner.first};
    m[logs[i].name]+=logs[i].diff;
    ++mf[m[logs[i].name]];
    singlewinnerpos = singlewinnerpos && m[logs[i].name] == mf.rbegin()->first && mf.rbegin()->second == winner.second && winner.second == 1;
    if (pair<int,int>{mf.rbegin()->first,mf.rbegin()->second} != winner) {
      winner = {mf.rbegin()->first, mf.rbegin()->second};
      if (!singlewinnerpos) ++changes;
    }
  }

  cout << changes;

  return 0;
}
