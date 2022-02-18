class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i {0}; i < k; ++i) {
          int place{0};
          while (place != num.size() - 1 && num[place] <= num[place + 1]) ++place;
          num.erase(place, 1);
          if (num.size() == 0) {
            num.push_back('0');
            break;
          }
        }
        while (num.size() > 1 && num[0] == '0') num.erase(0, 1);
        return num;
    }
};
