#include <stack>
#include <vector>
using std::vector;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> all;
        if (root == NULL) {
          return all;
        }
        std::stack<TreeNode> s;
        s.push(*root);
        while (!s.empty()) {
          TreeNode next = s.top();
          s.pop();
          if (next.right) s.push(*next.right);
          if (next.left) s.push(*next.left);
          all.push_back(next.val);
        }
        return all;
    }
};
