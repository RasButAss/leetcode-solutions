// https://leetcode.com/problems/binary-tree-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> ret;
  vector<vector<int>> levelOrder(TreeNode* root, int level = 0) {
    if (!root) return {};
    if (ret.size() == level) ret.push_back({});
    ret[level].push_back(root->val);
    levelOrder(root->left, level + 1);
    levelOrder(root->right, level + 1);

    if (level == 0)
      return ret;
    else
      return {};
  }
};
