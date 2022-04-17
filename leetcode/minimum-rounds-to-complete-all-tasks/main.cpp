class Solution {
  public:
    int minimumRounds(vector < int > & tasks) {
      map < int, int > occur;
      for (auto task: tasks) {
        ++occur[task];
      }
      int totalRounds {
        0
      };
      for (const auto & [difficulty, value]: occur) {
        int temprounds;
        int firstNum {
          0
        };
        int maxFirstNum {
          0
        };
        while (firstNum + 3 <= value || firstNum == value) {
          firstNum += 3;
          // cout << 1 << " " << value << " " << firstNum << std::endl;
          if ((value - firstNum) % 2 == 0) {
            maxFirstNum = firstNum;
          }
        }
        int secNum {
          0
        };
        int maxSecNum {
          0
        };
        while (secNum + 2 <= value || secNum == value) {
          secNum += 2;
                    // cout << 2 << " " << value << " " << secNum << std::endl;
          if ((value - secNum) % 3 == 0) {
            maxSecNum = secNum;
          }
        }
        if (maxFirstNum == 0 && maxSecNum == 0) {
          temprounds = -1;
        } else {
          // cout << difficulty << " " << value << " " << maxFirstNum << " " << maxSecNum << std::endl;
          maxFirstNum = maxFirstNum / 3 + (value - maxFirstNum) / 2;
          maxSecNum = maxSecNum / 2 + (value - maxSecNum) / 3;
          if (maxFirstNum <= maxSecNum) {
            temprounds = maxFirstNum;
          } else {
            temprounds = maxSecNum;
          }
        }
        // cout << difficulty << " " << temprounds << std::endl;
        if (temprounds == -1) {
          return -1;
        }
        totalRounds += temprounds;
      }
      return totalRounds;
    }
};
