// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
  int pseudoPalindromicPaths(TreeNode* root, int pref = 0) {
    if (root == nullptr)
      return 0;
    else {
      pref ^= 1 << root->val;
      if (root->left == nullptr and root->right == nullptr)
        return ((!pref) or !(pref & (pref - 1)));
      else
        return pseudoPalindromicPaths(root->left, pref) +
               pseudoPalindromicPaths(root->right, pref);
    }
  }
};
