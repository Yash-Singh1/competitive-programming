class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
      int offset{0};
      unsigned long currentSize{words.size() - 1};
        for (int i{0}; i < currentSize; ++i) {
          map<char, int> occ;
          for (auto word: words[i - offset]) {
            occ[word]++;
          }
          bool fail = false;
          for (auto word: words[i + 1 - offset]) {
            if (occ.find(word) == occ.end()) {
              cout << words[i - offset] << endl;
              fail = true;
              break;
            } else{
              occ[word]--;
              cout << words[i - offset] << " 2" << endl;
              if (occ[word] < 0) {
                fail = true;
                break;
              }
            }
          }
          for (auto const& [key, val] : occ) {
            if (val != 0) {
              fail = true;
              break;
            }
          }
          if (!fail) {
            for (auto word: words) {
              cout << word << " ";
            }
            cout << endl;
            words.erase(words.begin() + i + 1 - offset);
            ++offset;
          }
        }
      return words;
    }
};
