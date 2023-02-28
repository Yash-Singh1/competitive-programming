#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> freq(71);
  ll x;
  for (ll i{0}; i < n; ++i) {
    cin >> x;
    ++freq[x];
  }

  // Calculate prime factorizations for everything 1-70
  vector<ll> primefact(71);
  vector<bool> prime(71, 1);
  vector<ll> primes;
  for (ll i{2}; i <= 70; ++i) {
    if (prime[i]) {
      primes.push_back(i);
      for (ll j{i*i}; j <= 70; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (ll i{0}; i < (ll)primes.size(); ++i) {
    primefact[primes[i]] = 1<<i;
  }
  for (ll i{2}; i <= 70; ++i) {
    for (auto &prim: primes) {
      if (i*prim <= 70) {
        primefact[i*prim] = primefact[i] ^ primefact[prim];
      }
    }
  }

  vector<ll> twopow(n+1);
  twopow[0] = 1;
  for (ll i{1}; i <= n; ++i) {
    twopow[i] = (twopow[i - 1] * 2) % MOD;
  }

  vector<ll> dp1(1<<19);
  dp1[0] = 1;
  vector<ll> dp2(1<<19);
  for (ll i{1}; i <= 70; ++i) {
    if (!freq[i]) continue;
    for (ll j{0}; j < (1<<19); ++j) {
      dp2[j] = 0;
    }
    for (ll j{0}; j < (1<<19); ++j) {
      dp2[j^primefact[i]] += (dp1[j] * (twopow[freq[i]-1])) % MOD;
      dp2[j^primefact[i]] %= MOD;
      dp2[j] += (dp1[j] * (twopow[freq[i]-1])) % MOD;
      dp2[j] %= MOD;
    }
    swap(dp1, dp2);
  }

  cout << dp1[0]-1 << "\n";

  return 0;
}
