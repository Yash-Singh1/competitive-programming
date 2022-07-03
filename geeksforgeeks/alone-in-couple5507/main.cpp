class Solution{
    public:
    int findSingle(int N, int arr[]){
        int ans{arr[0]};
        for (int i{1}; i < N; ++i) {
            ans ^= arr[i];
        }
        return ans;
    }
};
