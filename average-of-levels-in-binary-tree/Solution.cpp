// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
  vector<double> tot;
  vector<int> cnt;

  vector<double> averageOfLevels(TreeNode* root, int level = 0) {
    if (root == nullptr) return {};
    if (tot.size() == level)
      tot.push_back(root->val), cnt.push_back(1);
    else
      tot[level] += root->val, ++cnt[level];
    averageOfLevels(root->left, level + 1);
    averageOfLevels(root->right, level + 1);

    if (level == 0) {
      for (int i = 0, n = tot.size(); i < n; ++i) tot[i] /= cnt[i];
      return tot;
    } else
      return {};
  }
};
