#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("input", "r", stdin);

  ll n{255};

  int a[n];
  priority_queue<int> pq;
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    pq.push(a[i]);
  }

  int sm{0};
  sm += pq.top();
  pq.pop();
  sm += pq.top();
  pq.pop();
  sm += pq.top();
  pq.pop();

  cout << sm << "\n";

  return 0;
}
