#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = __LONG_LONG_MAX__-1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
const ll B = 27;

ll mulmod(ll a, ll b, ll m) {
  return (ll)(((__int128)a * (__int128)b) % m);
}

ll addmod(ll a, ll b, ll m) {
  return (ll)(((((__int128)a + (__int128)b) % m) + m) % m);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string n, h;
  cin >> n >> h;

  if (n.size() > h.size()) {
    cout << 0 << "\n";
    return 0;
  }

  ll nsz{(ll)n.size()}, hsz{(ll)h.size()};

  // sliding window, if frequency tables match (26 characters), insert hash into set
  vector<ll> pows(hsz);
  pows[0] = 1;
  for (ll i{1}; i < hsz; ++i) {
    pows[i] = mulmod(pows[i - 1], B, M);
  }

  vector<ll> roll(hsz);
  for (ll i{0}; i < hsz; ++i) {
    roll[i] = addmod((i == 0 ? 0 : mulmod(roll[i - 1], B, M)), h[i] - 'a', M);
    // roll[i] = addmod(mulmod(pows[i], (h[i] - 'a') + 1, M), (i == 0 ? 0 : roll[i - 1]), M);
  }
  // cout << roll[2] << " " << (roll[6] - roll[3]) << "\n";

  unordered_map<char,int> freq, slide;
  for (ll i{0}; i < nsz; ++i) {
    ++freq[n[i]]; ++slide[h[i]];
  }
  for (char i{'a'}; i <= 'z'; ++i) {
    if (freq.find(i) == freq.end()) freq[i] = 0;
    if (slide.find(i) == slide.end()) slide[i] = 0;
  }
  unordered_set<ll> perms;
  for (ll i{0}; i <= hsz - nsz; ++i) {
    bool good{1};
    for (char j{'a'}; j <= 'z'; ++j) {
      good &= (freq[j] == slide[j]);
    }
    if (good) {
      // cout << i << " " << addmod(addmod(roll[i + nsz - 1], -(i == 0 ? 0 : roll[i - 1]), M), M, M) << " " << pows[i] << " " << binpow(pows[i], M - 2, M) << " ";
      // ll newe{mulmod(addmod(addmod(roll[i + nsz - 1], -(i == 0 ? 0 : roll[i - 1]), M), M, M), binpow(pows[i], M - 2, M), M) % M};
      ll newe = addmod(roll[i + nsz - 1], (i == 0 ? 0 : mulmod(-roll[i - 1], pows[nsz], M)), M); 
      // cout << newe << "\n";
      perms.insert(newe);
    }
    --slide[h[i]];
    if (i != hsz - nsz) {
      ++slide[h[i + nsz]];
    }
  }

  cout << perms.size() << "\n";

  return 0;
}
