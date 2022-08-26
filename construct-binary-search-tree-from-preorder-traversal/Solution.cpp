// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
  TreeNode* bstFromPreorder(vector<int>& preorder, int l, int r) {
    TreeNode* ret = new TreeNode(preorder[l]);
    int start = l, end = r;
    while (end - start > 1) {
      int mid = (start + end) >> 1;
      if (preorder[mid] > preorder[l])
        end = mid;
      else
        start = mid;
    }

    if (end > l + 1) ret->left = bstFromPreorder(preorder, l + 1, end);
    if (end < r) ret->right = bstFromPreorder(preorder, end, r);

    return ret;
  }
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return bstFromPreorder(preorder, 0, preorder.size());
  }
};
