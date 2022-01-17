/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, string> m;
        std::stringstream ss;
        vector<string> completedWords;
        ss << s;
        int i {0};
        while (!ss.eof()) {
            string nextWord;
            ss >> nextWord;
            if (std::find(completedWords.begin(), completedWords.end(), nextWord) != completedWords.end() && m.find(pattern[i]) == m.end()) {
                return false;
            }
            completedWords.push_back(nextWord);
            m.insert(std::make_pair(pattern[i], nextWord));
            if (m[pattern[i]] != nextWord) {
                return false;
            }
            ++i;
        }
        if (pattern.length() > i) {
            return false;
        }
        return true;
    }
};
// @lc code=end

