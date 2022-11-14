#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> merge(pair<long long, long long> a, pair<long long, long long> b) {
  a.first = max(a.first, b.first);
  a.second = min(a.second, b.second);
  return a;
}

pair<long long, long long> op(pair<long long, long long> a, pair<long long, long long> b, bool sub) {
  a.first = max(a.first + (sub ? b.second : b.first) * (sub ? -1 : 1), 0LL);
  a.second = max(a.second + (sub ? b.first : b.second) * (sub ? -1 : 1), 0LL);
  return a;
}

int main()
{
  ofstream fout("traffic.out");
  ifstream fin("traffic.in");

  long long n;
  fin >> n;

  pair<long long, pair<long long, long long>> a[n];

  for (long long i{0}; i < n; ++i) {
    string s;
    fin >> s;
    if (s == "on") {
      a[i].first = 1;
    } else if (s == "off") {
      a[i].first = -1;
    } else {
      a[i].first = 0;
    }
    fin >> a[i].second.first >> a[i].second.second;
  }

  pair<long long, long long> res[n];

  for (long long i{0}; i < n; ++i) {
    if (a[i].first == 0) {
      res[i] = a[i].second;
    } else {
      res[i].first = -1;
      res[i].second = -1;
    }
  }

  for (long long i{1}; i < n; ++i) {
    if (res[i - 1].first != -1) {
      if (a[i].first == 1) {
        res[i] = op(res[i - 1], a[i].second, 0);
      } else if (a[i].first == -1) {
        res[i] = op(res[i - 1], a[i].second, 1);
      } else {
        res[i] = merge(res[i - 1], a[i].second);
        res[i - 1] = res[i];
      }
    }
  }
  pair<long long, long long> secans{res[n - 1]};
  pair<long long, long long> res2[n];

  for (long long i{0}; i < n; ++i) {
    if (a[i].first == 0) {
      res2[i] = a[i].second;
    } else {
      res2[i].first = -1;
      res2[i].second = -1;
    }
  }
  for (long long i{n - 2}; i >= 0; --i) {
    if (res2[i + 1].first != -1) {
      if (a[i].first == 1) {
        res2[i] = op(res2[i + 1], a[i].second, 1);
      } else if (a[i].first == -1) {
        res2[i] = op(res2[i + 1], a[i].second, 0);
      } else {
        res2[i] = merge(res2[i + 1], a[i].second);
      }
    }
  }
  fout << res2[0].first << " " << res2[0].second << "\n";
  fout << secans.first << " " << secans.second << "\n";
}
