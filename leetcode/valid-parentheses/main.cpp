class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (auto bracket: s) {
          if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push_back(bracket);
          } else if (stack.size() == 0) {
            return false;
          } else if ((bracket == ')' && stack[stack.size() - 1] == '(') || (bracket == '}' && stack[stack.size() - 1] == '{') || (bracket == ']' && stack[stack.size() - 1] == '[')) {
             stack.pop_back();
          } else {
            return false;
          }
        }
      if (stack.size() == 0) {
        return true;
      }
      return false;
    }
};
