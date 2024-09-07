// https://leetcode.com/problems/search-in-a-binary-search-tree

class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL or root->val == val) return root;
    return searchBST((val < root->val) ? root->left : root->right, val);
  }
};
