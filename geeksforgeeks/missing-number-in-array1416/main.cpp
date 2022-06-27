class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int ans{array[0]};
        for (int i{1}; i < array.size(); ++i) {
            ans ^= array[i];
        }
        for (int i{1}; i <= n; ++i) {
            ans ^= i;
        }
        return ans;
    }
};
