#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  long long n, m, r;
  cin >> n >> m >> r;
  
  long long c[n];
  long long makingmilk{0};
  for (long long i{0}; i < n; ++i) {
    cin >> c[i];
    makingmilk += c[i];
  }
  sort(c, c + n);

  pair<long long, long long> milk[m];
  for (long long i{0}; i < m; ++i) {
    cin >> milk[i].second >> milk[i].first;
  }
  sort(milk, milk + m, std::greater{});
  long long milk2[m];
  milk2[0] = milk[0].second;
  for (long long i{1}; i < m; ++i) {
    milk2[i] = milk2[i - 1] + milk[i].second;
  }
  long long milk3[m];
  milk3[0] = milk[0].first * milk[0].second;
  for (long long i{1};i<m;++i) {
    milk3[i] = milk3[i - 1] + (milk[i].first * milk[i].second);
  }

  long long rented[r];
  for (long long i{0}; i < r; ++i) {
    cin >> rented[i];
  }
  sort(rented, rented + r, std::greater{});

  long long ans{-1};
  long long renttot{0};
  for (long long i{-1}; i < n && i < r; ++i) {
    if (i >= 0) {
      renttot += rented[i];
      makingmilk -= c[i];
    }
    long long low{0};
    long long high{min(m - 1, n - i - 1)};
    long long ansb{-1};
    while (low <= high) {
      long long mid{(low + high) / 2};
      if (milk2[mid] < makingmilk) {
        low = mid + 1;
        ansb = mid;
      } else if (milk2[mid] > makingmilk) {
        high = mid - 1;
      } else {
        ansb = mid;
        break;
      }
    }
    long long amount{renttot};
    if (ansb != -1) {
      amount += milk3[ansb];
    }
    if (ansb + 1 < m) {
      amount += (makingmilk-(ansb == -1 ? 0 : milk2[ansb])) * milk[ansb+1].first;
    }
    ans = max(amount, ans);
  }

  cout << ans;

  return 0;
}
