#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;

class FenwickTree {
private:
  vll ft;
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }

  void build(const vll &f) {
    int m = (int)f.size()-1;
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {
      ft[i] += f[i];
      if (i+LSOne(i) <= m)
        ft[i+LSOne(i)] += ft[i];
    }
  }

  FenwickTree(const vll &f) { build(f); }

  FenwickTree(int m, const vi &s) {
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)
      ++f[s[i]];
    build(f);
  }

  FenwickTree(int m, const vi &s, int x, int y) {
    vll f(m+1, 0);
    for (int i = x; i <= y; ++i)
      ++f[s[i]];
    build(f);
  }

  ll rsq(int j) {
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (i+p < (int) ft.size() && k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  vector<int> a2(n);
  vector<pii> compress(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    compress[i] = {a[i], i};
  }
  sort(compress.begin(), compress.end());
  int j{1}, j2{1};
  unordered_map<int,int> decompress;
  map<int, pii> decompressp;
  for (int i{0}; i < n; ++i) {
    if (i == 0 || compress[i - 1].first != compress[i].first) {
      decompress[j] = compress[i].first;
      a[compress[i].second] = j;
      a2[compress[i].second] = j2;
      decompressp[j2] = compress[i];
      ++j; ++j2;
    } else {
      a[compress[i].second] = j;
      a2[compress[i].second] = j2;
      decompressp[j2] = compress[i];
      ++j2;
    }
  }

  // median advance k - 1 / 2
  FenwickTree ft(200001);
  // , a2, 0, k - 1
  FenwickTree st(200001);
  for (int i{0}; i < k; ++i) {
    ft.update(a2[i], 1);
    st.update(a2[i], decompressp[a2[i]].first);
  }

  for (int i{0}; i < n - k + 1; ++i) {
    int mf{ft.select((k + 1) / 2)};
    cout << (decompressp[mf].first * (k - (k / 2))) - st.rsq(mf) + (st.rsq(mf+1, 200000) - (decompressp[mf].first * (k / 2))) << " ";
    if (i + k < n) {
      ft.update(a2[i + k], 1);
      st.update(a2[i + k], decompressp[a2[i + k]].first);
    }
    ft.update(a2[i], -1);
    st.update(a2[i], -decompressp[a2[i]].first);
  }
  cout << "\n";

  return 0;
}
