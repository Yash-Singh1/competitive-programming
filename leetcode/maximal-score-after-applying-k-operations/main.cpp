typedef long long ll;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      multiset<int> s;
      ll ans{0};
      for (auto &el: nums) {
        s.insert(el);
      }
      for (int i{0}; i < k; ++i) {
        int big{*s.rbegin()};
        ans += big;
        s.insert((int)ceil((double)(big) / 3));
        s.erase(s.find(big));
      }
      return ans;
    }
};
