/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int lowDigits{static_cast<int>(log10(low)) + 1};
        int highDigits{static_cast<int>(log10(high)) + 1};
        vector<int> nums;
        for (int digits{lowDigits}; digits <= highDigits; ++digits)
        {
            for (int start{1};
                 start <= 10 - digits; ++start)
            {
                int value{start * static_cast<int>(pow(10, digits - 1))};
                for (int next{1}; next <= digits - 1; ++next)
                {
                    value += (start + next) * pow(10, digits - 1 - next);
                }
                if (value < low)
                {
                    continue;
                }
                else if (value > high)
                {
                    break;
                }
                nums.push_back(value);
            }
        }
        return nums;
    }
};
// @lc code=end
