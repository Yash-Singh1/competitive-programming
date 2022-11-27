class Solution {
  public:
    long long maxScore(vector<int>& nums) {
        long long score{0};
        unordered_map<int,int>m;
        for (int i{0}; i < nums.size(); ++i) {
            if (m.find(nums[i] - i) == m.end()) m[nums[i] - i] = 0;
            score += i - m[nums[i] - i];
            ++m[nums[i] - i];
        }
        return score;
    }
};
