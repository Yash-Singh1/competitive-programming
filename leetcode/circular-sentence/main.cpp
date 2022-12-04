class Solution {
public:
    bool isCircularSentence(string sentence) {
      for (int i{0}; i < sentence.size(); ++i) {
        if (i != 0 && sentence[i - 1] == ' ') {
          if (sentence[i-2] != sentence[i]) return 0;
        }
      }
      return sentence[0] == sentence[sentence.size()-1];
    }
};
