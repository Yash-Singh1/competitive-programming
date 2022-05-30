// Doesn't work at all, extreme WIP
// ran out of time...

#include<iostream>
#include<map>
using namespace std;
#define MOD 1000000009

int fiveAns[100001];
int twooneAns[100001];

int binpow(int a, int n) {
    if (a == 5) {
        if (fiveAns[n]) {
            return fiveAns[n];
        }
    } else if (a == 21 && twooneAns[n]) {
        return twooneAns[n];
    }
    int storen{n};
    int storea{a};
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        n /= 2;
    }
    if (storea == 5) {
        fiveAns[storen] = res;
    } else if (storea == 21) {
        twooneAns[storen] = res;
    }
    return res;
}

// map<int, int> facts;

long long fact(long long n, long long stop = 1) {
    // int storen {n};
    // if (facts.find(n) != facts.end()) {
    //     std::cout << "getting: " << n << " " << facts[n] << std::endl;
    //     return facts[n];
    // }
    long long res = 1;
    while (n > stop) {
        // if (facts.find(n) != facts.end()) {
        //             std::cout << "getting-m: " << n << " " << facts[n] << std::endl;
        //     res *= facts[n];
        //     res %= MOD;
        //     break;
        // }
        res *= n;
        res %= MOD;
        --n;
    }
    // if (stop == 1) {
    // std::cout << "setting: " << storen << " " << res << std::endl;
    // facts[storen] = res;
    // }
    return res;
}

long long comb(long long n, long long r) {
    std::cout << n << " " << r << " " << fact(n + r - 1) << " " << fact(n - 1) << " " << fact(r) << "\n";
    return (fact(n + r - 1) / (fact(n - 1) * fact(r))) % MOD;
}

int main()
 {
	long long t;
	cin >>t;
	++t;
	while (--t) {
	    long long l, r;
	    cin >> l >> r;
	    l %= MOD;
	    r %= MOD;
	    //std::cout << (l - r == 0 || r == 0 ? 0 : std::max(r, l - r)) << " " << binpow(2, (l - r == 0 || r == 0 ? 0 : std::max(r, l - r))) % MOD << "\n";
	    //std::cout << binpow(5, r) * binpow(21, l - r) % MOD * fact(l) % MOD << "\n";
	    std::cout << comb(21, l - r) << " " << comb(5, r) << " " << fact(l) % MOD << "\n";
	    //std::cout << comb(5, r) * comb(21, l - r) % MOD * fact(l) % MOD << "\n";
	}
	return 0;
}
