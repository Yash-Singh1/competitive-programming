class Solution {
  public:
    vector<int> solve(vector<int>& a) {
        vector<int> ans;
        for (int k{0}; k < a.size(); k++) {
            int ro{1},lo{1};
            int ki{0};
            while (true) {
                //cout << k - ro << " " << k << " " << k + lo << endl;
                if ((k - ro) >= 0 && a.at(k - ro) <= a.at(k)) {
                    ++ro;
                    ++ki;
                } else if ((k + lo) < a.size() && a.at(k + lo) <= a.at(k)) {
                    ++lo;
                    ++ki;
                } else {
                    break;
                }
            }
            ans.push_back(ki);
        }
        return ans;
    }
};