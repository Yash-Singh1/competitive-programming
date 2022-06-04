// NOTE: Instead of iterating down and up through all possibilities, use binary search from 0 -> 10^10 and validate each number

class Solution{
public:
    bool valid(long num, long N, long A[], long M, long L, long H[]) {
        long long tot{0};
        for (long i{0}; i < N; ++i) {
            long speed{H[i] + (A[i] * num)};
            if (H[i] + (A[i] * num) > L) {
                tot += speed;
            }
        }
        if (tot > M) {
            return true;
        }
        return false;
    }
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long low{0};
        long high{10000000000};
        long ans;
        while (low <= high) {
            long mid=(low + high) / 2;
            if (valid(mid, N, A, M, L, H)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
