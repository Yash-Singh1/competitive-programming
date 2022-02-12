class Solution {
public:
    int romanToInt(string s) {
        int place{1};
        reverse(s.begin(), s.end());
        int val {0};
        for (int i{0}; i < s.size(); ++i) {
          int shownPlace{1};
          if (s[i] == 'M') {
            shownPlace = 1000;
          } else if (s[i] == 'D') {
            shownPlace = 500;
          } else if (s[i] == 'C') {
            shownPlace = 100;
          } else if (s[i] == 'L') {
            shownPlace = 50;
          } else if (s[i] == 'X') {
            shownPlace = 10;
          } else if (s[i] == 'V') {
            shownPlace = 5;
          }
          if (shownPlace < place) {
            val -= shownPlace;
          } else {
            val += shownPlace;
            place = shownPlace;
          }
        }
      return val;
    }
};
