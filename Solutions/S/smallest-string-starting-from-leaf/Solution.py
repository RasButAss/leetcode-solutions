# https://leetcode.com/problems/smallest-string-starting-from-leaf/

class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        def work(root, pref, best):
            cur = chr(ord('a') + root.val) + pref
            if not root. left and not root. right:
                if not best[0] or cur < best[0]:
                    best[0] = cur
            for child in [root.left, root.right]:
                if child:
                    work(child, cur, best)
        best = [""]
        work(root, "", best)
        return best[0]
