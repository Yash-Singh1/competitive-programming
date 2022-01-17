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
        vector<int> nodes;
        if (root == NULL) {
          return nodes;
        }
        nodes.push_back(root->val);
        vector<int> leftNodes {preorderTraversal((*root).left)};
        nodes.insert(nodes.end(), leftNodes.begin(), leftNodes.end());
        leftNodes.clear();
        vector<int> rightNodes {preorderTraversal((*root).right)};
        nodes.insert(nodes.end(), rightNodes.begin(), rightNodes.end());
        rightNodes.clear();
        return nodes;
    }
};
