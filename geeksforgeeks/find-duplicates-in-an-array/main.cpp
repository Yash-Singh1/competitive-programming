// TLE, requires minor performance optimizations

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        map<int, int> m;
        vector<int> ans;
        bool did{false};
        for (int i{0}; i < n; ++i) {
            if (!m[arr[i]]) {
                m[arr[i]] = 1;
            } else if (m[arr[i]] == 1) {
                did = true;
                m[arr[i]] = 2;
            }
        }
        if (!did) {
            return vector<int>{-1};
        }
        map<int, int>::iterator it = m.begin();
        while (it != m.end()) {
            if (it->second == 2) {
                ans.push_back(it->first);
            }
            ++it;
        }
        return ans;
    }
};
