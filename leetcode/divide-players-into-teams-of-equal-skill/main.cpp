class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      sort(skill.begin(), skill.end());
      long long f{skill[0] + skill[skill.size()-1]};
      long long c{0};
      for (int i{0}; i < skill.size()/2; ++i) {
        c += skill[i] * skill[skill.size() - i - 1];
        if (skill[i] + skill[skill.size() - i - 1] != f) return -1;
      }
      return c;
    }
};
