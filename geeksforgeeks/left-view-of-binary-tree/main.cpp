int dp[101];

int rec(Node *root, int dist) {
    if (root == NULL) {
        return dist;
    }
    if (dp[dist] == -1) {
        dp[dist] = root->data;
    }
    int mx{rec(root->left, dist + 1)};
    int mx2{rec(root->right, dist + 1)};
    if (mx2 > mx) {
        mx = mx2;
    }
    return mx;
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    for (int i{0}; i < 101; ++i) {
        dp[i] = -1;
    }
    vector<int> a;
    int j=rec(root, 0);
    for (int i{0}; i < j; ++i) {
        a.push_back(dp[i]);
    }
   return a;
}
