class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int x{0};
        for (auto &v: array) {
            x ^= v;
        }
        for (int i{0}; i < n; ++i) {
            x ^= i+1;
        }
        return x;
    }
};
