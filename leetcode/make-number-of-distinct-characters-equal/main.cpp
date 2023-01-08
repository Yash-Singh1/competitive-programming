class Solution {
public:
    bool isItPossible(string word1, string word2) {
      set<char> m1, m2;
      map<char, int> tot1, tot2;
      for (auto &ch: word1) {
        m1.insert(ch);
        ++tot1[ch];
      }
      for (auto &ch: word2) {
        m2.insert(ch);
        ++tot2[ch];
      }
      if ((int)m1.size() == (int)m2.size()) {
        if (m1.size() == 1 && m2.size() == 1 && ((word1.size() == 1 && word2.size() > 1) || (word2.size() == 1 && word1.size() > 1))) {
          return false;
        }
        return true;
      }
      if (abs((int)m1.size() - (int)m2.size()) == 1) {
        map<char,int> *to1, *to2;
        to1 = &tot1;
        to2 = &tot2;
        if (m1.size() > m2.size()) {
          to1 = &tot2;
          to2 = &tot1;
        }
        bool found{0};
        for (char i{'a'}; i <= 'z'; ++i) {
          if ((*to2)[i] > 1 && (*to1)[i] == 0) {
            found = 1;
          }
        }
        bool founda{0};
        for (char i{'a'}; i <= 'z'; ++i) {
          if ((*to1)[i] > 1 && (*to2)[i] > 0) {
            founda = 1;
          }
        }
        if (!(found && founda)) {
          found = 0;
          founda = 0;
          for (char i{'a'}; i <= 'z'; ++i) {
            if ((*to2)[i] == 1 && (*to1)[i] == 0) {
              found = 1;
            }
          }
          for (char i{'a'}; i <= 'z'; ++i) {
            if ((*to1)[i] > 1 && (*to2)[i] == 0) {
              founda = 1;
            }
          }
          if (!(found && founda)) {
            found = 0;
            founda = 0;
            for (char i{'a'}; i <= 'z'; ++i) {
              if ((*to2)[i] == 1 && (*to1)[i] == 0) {
                found = 1;
              }
            }
            for (char i{'a'}; i <= 'z'; ++i) {
              if ((*to1)[i] == 1 && (*to2)[i] > 0) {
                founda = 1;
              }
            }
          }
        }
        return found && founda;
      }
      if (abs((int)m1.size() - (int)m2.size()) == 2) {
        map<char,int> *to1, *to2;
        to1 = &tot1;
        to2 = &tot2;
        if (m1.size() > m2.size()) {
          to1 = &tot2;
          to2 = &tot1;
        }
        bool found{0};
        for (char i{'a'}; i <= 'z'; ++i) {
          if ((*to2)[i] >= 1 && (*to1)[i] > 1) {
            for (char j{'a'}; j <= 'z'; ++j) {
              if (i != j) {
                if ((*to2)[j] == 1 && (*to1)[j] == 0) {
                  if (word1 == "buebek") cout << i << " " << j << "\n";
                  found = 1;
                }
              }
            }
          }
        }
        return found;
      }
      return false;
    }
};
