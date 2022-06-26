class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
        vector<long long> v(k, 0);
        long long tot{0};
        for (int i{0}; i < n; ++i) {
            if (v[(k - (A[i] % k)) % k] > 0) {
                tot += v[(k - (A[i] % k)) % k];
            }
            v[A[i] % k]++;
        }
        return tot;
    }
};
