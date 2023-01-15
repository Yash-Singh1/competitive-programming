typedef long long ll;

class Solution {
public:
    ll countGood(vector<int>& nums, int k) {
      int n{(int)nums.size()};
      int l{0}, r{0};
      map<int,int> f;
      int goodness{0};
      ll ans{0};
      while (l < n) {
        while (r < n && goodness < k) {
          goodness += f[nums[r]];
          ++f[nums[r]];
          ++r;
        }
        if (goodness >= k) ans += n - r + 1;
        goodness -= f[nums[l]] - 1;
        --f[nums[l]];
        ++l;
      }
      return ans;
    }
};
