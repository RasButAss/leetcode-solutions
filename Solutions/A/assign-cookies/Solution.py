# https://leetcode.com/problems/assign-cookies/

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g, s = sorted(g), sorted(s)
        i, n = 0, len(g)
        for x in s:
            if i < n and g[i] <= x:
                i += 1
        return i
