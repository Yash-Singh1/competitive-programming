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

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }

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
