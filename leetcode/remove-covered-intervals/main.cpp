class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        unsigned long intervalsSize{intervals.size()};
        for (unsigned long i {0}; i < intervals.size(); ++i) {
            for (unsigned long j{0}; j < intervals.size(); ++j) {
                if (i != j && intervals[j][0] <= intervals[i][0] &&
                    intervals[j][1] >= intervals[i][1]
                ) {
                    --intervalsSize;
                    break;
                }
            }
        }
        return static_cast<int>(intervalsSize);
    }
};
