// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
  TreeNode* sortedArrayToBST(vector<int>& nums, int l = 0, int r = -1) {
    if (r == -1) r = nums.size() - 1;
    int m = (l + r) >> 1;

    TreeNode* ret = new TreeNode(nums[m]);
    if (m > l) ret->left = sortedArrayToBST(nums, l, m - 1);
    if (m < r) ret->right = sortedArrayToBST(nums, m + 1, r);

    return ret;
  }
};
