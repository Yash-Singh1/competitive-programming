vector<long long> prime;

class Solution{
public:
    long long primeProduct(long long L, long long R){
        vector<bool> smaller(sqrt(R), true);
        for (long long i{2}; i <= sqrt(R); ++i) {
            if (smaller[i]) {
                prime.push_back(i);
                for (long long j{i * i}; j <= sqrt(R); j += i) {
                    smaller[j] = false;
                }
            }
        }
        vector<bool> isPrime(R - L + 1, true);
        for (long long divisor: prime) {
            long long start{L / divisor * divisor};
            if (start < L) {
                start += divisor;
            }
            if (start == divisor) {
                start += divisor;
            }
            //std::cout << "c " << start << " " << divisor << "\n";
            for (long long i{start}; i <= R; i += divisor) {
                //std::cout << i << " " << start << "\n";
                isPrime[i - L] = false;
            }
        }
        long long ans{1};
        for (long long i{L}; i <= R; ++i) {
            if (isPrime[i - L] == true) {
                //std::cout << ans <<" " << i <<"\n";
                ans *= i;
                ans %= 1000000007;
            }
        }
        return ans;
    }
};
