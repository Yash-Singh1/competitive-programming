#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll M = 1e9+7;
const ll B = 27;
class HashedString {
	private:
		static vector<ll> pow;
		vector<ll> p_hash;
	public:
		HashedString(const string& s) : p_hash(s.size() + 1) {
			while (pow.size() < s.size()) {
				pow.push_back((pow.back() * B) % M);
			}

			p_hash[0] = 0;
			for (int i = 0; i < (int)s.size(); i++) {
				p_hash[i + 1] = ((p_hash[i] * B) % M + (s[i] - 'a' + 1)) % M;
			}
		}

		ll getHash(int start, int end) {
			ll raw_val = (
				p_hash[end + 1] - (p_hash[start] * pow[end - start + 1])
			);
			return (raw_val % M + M) % M;
		}
};
vector<ll> HashedString::pow = {1};

struct Point {
  int x, y;
  double nangle, ndist;
  bool right;
  int dist(int x2, int y2) {
    return abs(x2 - x) + abs(y2 - y);
  }
  int angle(int x2, int y2, int x3, int y3) {
    // This assumes that point 2 comes before and point 3 after the current point
    // We get the answer by doing the acos of (x2*x3+y2*y3)/(sqrt(x2^2+y2^2)*sqrt(x3^2+y3^2))
    return ((y3 - y2) / (x3 - x2)) > 0 ? 90 : 270;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lightsout.in", "r", stdin);
  freopen("lightsout.out", "w", stdout);

  int n;
  cin >> n;

  vector<Point> ps(n);
  for (int i{0}; i < n; ++i) {
    cin >> ps[i].x >> ps[i].y;
  }
  for (int i{0}; i < n; ++i) {
    ps[i].nangle = ps[i].angle(ps[(i+n-1)%n].x, ps[(i+n-1)%n].y, ps[(i+1)%n].x, ps[(i+1)%n].y);
    ps[i].right = ps[i].nangle == 90;
    ps[i].ndist = ps[i].dist(ps[(i+1)%n].x, ps[(i+1)%n].y);
  }

  vector<int> distp(n+1);
  for (int i{1}; i <= n; ++i) {
    distp[i] = distp[i-1]+ps[i-1].ndist;
  }

  vector<int> path;
  for (int i{0}; i < n; ++i) {
    if (ps[i].right) {
      path.push_back(-1);
    } else {
      path.push_back(-2);
    }
    path.push_back(ps[i].ndist);
  }
  path.push_back(ps[0].right ? -1 : -2);

  map<vector<int>,int> c;
  for (int i{0}; i < n; ++i) {
    for (int j{i}; j <= n; ++j) {
      ++c[vector<int>(path.begin() + i*2, path.begin() + j*2)];
    }
  }

  int lg{0};
  for (int i{1}; i < n; ++i) {
    for (int j{i}; j <= n; ++j) {
      if (c[vector<int>(path.begin() + i*2, path.begin() + j*2)] > 1) continue;
      lg = max(lg, (min(distp[j], distp[n] - distp[j]) + (distp[j] - distp[i])) - min(distp[i], distp[n] - distp[i]));
      break;
    }
  }

  cout << lg << "\n";

  return 0;
}
