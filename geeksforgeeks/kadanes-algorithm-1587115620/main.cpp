class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long msum{-INT_MAX};
        long long sum{0};
        for (int i{0}; i < n; ++i) {
            if (sum < 0) {
                sum = arr[i];
            } else {
                sum += arr[i];
            }
            if (sum > msum) {
                msum = sum;
            }
        }
        return msum;
    }
};
