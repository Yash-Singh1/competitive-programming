class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> current;
        for (auto num: nums) {
          if (current.find(num) != current.end()) {
            current.erase(num);
          } else {
            current.insert(num);
          }
        }
      return *current.begin();
    }
};
