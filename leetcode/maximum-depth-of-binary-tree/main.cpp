/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
          return 0;
        }
        std::stack<TreeNode> s;
        std::stack<int> depthS;
        depthS.push(1);
        s.push(*root);
        int maxDepth{1};
        while (!s.empty()) {
          TreeNode next = s.top();
          s.pop();
          int nextDepth = depthS.top();
          depthS.pop();
          if (next.right) {
              s.push(*next.right);
              depthS.push(nextDepth + 1);
          }
          if (next.left) {
              s.push(*next.left);
              depthS.push(nextDepth + 1);
          }
          else if (!next.right && nextDepth > maxDepth) maxDepth = nextDepth;
        }
        return maxDepth;
    }
};
