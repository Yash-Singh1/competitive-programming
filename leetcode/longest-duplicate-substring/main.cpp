// TLEs but an example of making use of multiple forms of algorithms in one

typedef long long ll;

const ll MOD = 27292996856087;

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0;
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}

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
        if (b & (1LL<<pow)) {
            b &= b - 1LL;
            ans = mulmod(ans, curp, m);
            ans %= m;
        }
        ++pow;
        curp = mulmod(curp, curp, m);
        curp %= m;
    }
    return ans;
}

class Solution {
public:
    string longestDupSubstring(string s) {
        int n{(int)s.size()};
        vector<ll> rolling(n);
        vector<ll> terms(n);
        ll ans{0};
        ll term{1};
        for (int k{0}; k < n; ++k) {
            ans += ((s[k] - 'a') * term) % MOD;
            ans %= MOD;
            terms[k] = term;
            term = mulmod(term, 26LL, MOD);
            term %= MOD;
            rolling[k] = ans;
        }
        ll l{1}, r{n};
        int anss{0}, anse{-1};
        while (l <= r) {
            ll i{(l+r)/2};
            unordered_set<ll> existing;
            bool found{0};
            for (int j{0}; j + i <= n; ++j) {
                // j + i - 1 = end point, j = start point
                ll val{(mulmod(((rolling[j + i - 1] - (j == 0 ? 0 : rolling[j - 1])) + MOD) % MOD, binpow(terms[j], MOD - 2, MOD), MOD)) % MOD};
                if (existing.find(val) != existing.end()) {
                    anss = j;
                    anse = j + i - 1;
                    found = 1;
                    break;
                }
                existing.insert(val);
            }
            if (found) {
                l = i + 1;
            } else {
                r = i - 1;
            }
        }
        string anstr;
        for (int k{anss}; k <= anse; ++k) {
            anstr += s[k];
        }
        return anstr;
    }
};
