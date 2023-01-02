#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int id;
  TreeNode *parent;
  vector<TreeNode*> children;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  TreeNode *root = new TreeNode;
  *root = {
    0,
    nullptr,
    {},
  };

  int n;
  cin >> n;

  vector<int> g[n];
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  stack<TreeNode*> s;
  s.push(root);
  while (!s.empty()) {
    TreeNode *tp{s.top()};
    for (auto &ne: g[tp->id]) {
      if (tp->parent == nullptr || ne == tp->parent->id) {
        TreeNode *child = new TreeNode;
        *child = {
          ne,
          tp,
          {},
        };
        tp->children.push_back(child);
        s.push(child);
      }
    }
  }

  cout << "debugging placeholder\n";

  return 0;
}
