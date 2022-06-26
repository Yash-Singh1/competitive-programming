// WA, Compiler error

class Solution {
  public:
    int count(int n, vector<int>& friends, vector<int>& sandwiches) {
        stack<int>s;
        int thereA{0};
        int thereB{0};
        for (int i{sandwiches.size() - 1}; i >= 0; --i) {
            if (sandwiches[i]) {
                ++thereA;
            } else {
                ++thereB;
            }
            s.push(sandwiches[i]);
        }
        queue<int> q;
        int aC{0};
        int bC{0};
        for (auto friendy: friends) {
            if (friendy) {
                ++aC;
            } else {
                ++bC;
            }
            q.push(friendy);
        }
        while (true) {
            if (s.top() == queue.top()) {
                if (s.top()) {
                    --aC;
                    --thereA;
                } else {
                    --bC;
                    --thereB;
                }
                s.pop();
                queue.pop();
            } else {
                if (queue.top() && thereA == 0 && bC == 0) {
                    break;
                } else if (!queue.top() && thereB == 0 && aC == 0) {
                    break;
                }
            }
        }
        int tot{0};
        while (!q.empty()) {
            ++tot;
            q.pop();
        }
        return tot;
    }
};
