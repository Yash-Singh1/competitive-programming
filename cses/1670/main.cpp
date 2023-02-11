#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void hashit(vector<int> &val, ll *hs) {
  *hs = 0;
  for (int i{0}; i < 8; ++i) {
    *hs <<= 4;
    *hs |= val[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> first(9);
  for (int i{0}; i < 9; ++i) {
    cin >> first[i];
  }

  queue<ll> q;
  unordered_map<ll,int> dist;
  ll hs{0};
  hashit(first, &hs);
  dist[hs] = 0;
  q.push(hs);
  vector<int> u(9);
  while (!q.empty()) {
    ll vali = q.front();
    int rem{1};
    for (int i{0}; i < 8; ++i) {
      u[8-i-1] = (vali&(15<<(i*4)))>>(i*4);
      rem ^= u[8-i-1];
    }
    u[8] = rem;
    q.pop();
    hashit(u, &hs);
    if (hs == 305419896) {
      cout << dist[hs] << "\n";
      return 0;
    }
    int cd{dist[hs]};
    for (int i{0}; i < 9; ++i) {
      if (i < 6) {
        swap(u[i], u[i+3]);
        hashit(u, &hs);
        if (dist.find(hs) == dist.end()) {
          dist[hs] = cd + 1;
          q.push(hs);
        }
        swap(u[i], u[i+3]);
      }
      if (i % 3 != 2) {
        swap(u[i], u[i+1]);
        hashit(u, &hs);
        if (dist.find(hs) == dist.end()) {
          dist[hs] = cd + 1;
          q.push(hs);
        }
        swap(u[i], u[i+1]);
      }
    }
  }

  return 0;
}
