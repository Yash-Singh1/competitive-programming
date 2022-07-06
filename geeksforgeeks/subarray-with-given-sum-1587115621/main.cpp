// TLE, prob requires minor optimizations

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long sum{0};
        map<int, int> f;
        f[0] = -1;
        for (int i{0}; i < n; ++i) {
            sum += arr[i];
            f[sum] = i + 1;
            if (f[sum - s]) {
                //cout << sum << " " << s << endl;
                return vector<int>{max(f[sum - s], 0) + 1, i + 1};
            }
        }
        return vector<int>{-1};
    }
};
