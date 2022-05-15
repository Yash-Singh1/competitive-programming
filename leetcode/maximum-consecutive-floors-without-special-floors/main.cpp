class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int max{special.size() > 0 ? special[0] - bottom : 0};
        if (special.size() > 0 && top - special[special.size() - 1] > max) {
          max = top - special[special.size() - 1];
        }
        for (int i{1}; i < special.size(); ++i) {
          int temp{special[i] - special[i - 1] - 1};
          if (temp > max) {
            max = temp;
          }
        }
      return max;
    }
};
