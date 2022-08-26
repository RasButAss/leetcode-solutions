// https://leetcode.com/problems/subtree-of-another-tree

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
  bool isEqual(TreeNode* root, TreeNode* sub) {
    if (!root and !sub) return true;
    if (!root or !sub) return false;
    return root->val == sub->val and isEqual(root->left, sub->left) and
           isEqual(root->right, sub->right);
  }
  bool isSubtree(TreeNode* root, TreeNode* sub) {
    if (!root) return false;
    if (isSubtree(root->left, sub) or isSubtree(root->right, sub)) return true;
    return root->val == sub->val and isEqual(root, sub);
  }
};
