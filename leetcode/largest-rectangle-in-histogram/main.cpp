typedef pair<int,int> pii;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n{(int)heights.size()};
      vector<int> mxrec(n);
      stack<pii> s;
      for (int i{0}; i < n; ++i) {
        while (s.size() && s.top().second >= heights[i]) s.pop();
        if (s.size()) {
          mxrec[i] = (i - s.top().first) * heights[i];
        } else {
          mxrec[i] = (i + 1) * heights[i];
        }
        s.push({i, heights[i]});
      }
      stack<pii> b;
      int ans{0};
      for (int i{n - 1}; i >= 0; --i) {
        while (b.size() && b.top().second >= heights[i]) b.pop();
        if (b.size()) {
          mxrec[i] += (b.top().first - i - 1) * heights[i];
        } else {
          mxrec[i] += (n - i - 1) * heights[i];
        }
        ans = max(ans, mxrec[i]);
        b.push({i, heights[i]});
      }
      return ans;
    }
};
