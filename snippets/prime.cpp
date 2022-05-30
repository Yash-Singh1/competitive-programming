#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 100;
vector<int> prime;
vector<int> ls;

void sieve() {
    for (int i{2}; i < sqrt(N); ++i) {
        if (prime[i]) {
            ls.push_back(i);
            // Since all multiples between 2-i are already covered, we can safely start from i^2
            for (int j{i * i}; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int main() {
    prime.resize(N, 1);
    prime[0] = 0;
    prime[1] = 0;
    sieve();
    for (auto e: ls) {
        cout << e << " ";
    }
}
