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
            for (int j{i * 2}; j < N; j += i) {
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
