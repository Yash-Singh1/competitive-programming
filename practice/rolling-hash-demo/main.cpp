// Demonstration of using the rolling hash snippet for string hashing
// Could use improvements for edge cases with modular multiplication, but it's fine for now

typedef long long ll;

const ll MOD = (ll)1e9+7;

ll rolling[6];
ll terms[6];
ll cur{0};
ll term{1};

ll binpow(ll a, ll b, ll m) {
  if (b == 0) {
    return 1;
  } else if (a == 0) {
    return 0;
  }
  ll curp{a};
  ll pow{0};
  ll ans{1};
  while (b) {
    if (b & (1<<pow)) {
      b &= b - 1;
      ans *= curp;
      ans %= m;
    }
    ++pow;
    curp *= curp;
    curp %= m;
  }
  return ans;
}

ll queryHash(int i, int j) {
  return ((rolling[j] - (i == 0 ? 0 : rolling[i - 1])) * terms[i])%MOD;
}

int main() {
    string s{"abcabc"};
    int n{(int)s.size()};

    for (int i{0}; i < n; ++i) {
      cur += (term * (s[i] - 'a')) % MOD;
      cur %= MOD;
      rolling[i] = cur;
      terms[i] = term;
      term *= 26LL;
      term %= MOD;
    }

    terms[n - 1] = binpow(terms[n - 1], MOD - 2, MOD);
    for (int i{n - 1}; i > 0; --i) {
      terms[i - 1] = (terms[i] * 26LL) % MOD;
    }
    
    cout << queryHash(0, 2)%MOD << " " << queryHash(3, 5)%MOD << "\n";
}
