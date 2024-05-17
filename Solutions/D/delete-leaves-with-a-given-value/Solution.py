# https://leetcode.com/problems/delete-leaves-with-a-given-value/

class Solution:
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        if root.left:
            root.left = self.removeLeafNodes(root.left, target)
        if root.right:
            root.right = self.removeLeafNodes(root.right, target)

        if not root.left and not root.right and root.val == target:
            return None
        return root
