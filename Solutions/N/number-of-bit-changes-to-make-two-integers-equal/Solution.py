# https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/

class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return -1 if (n ^ k) & k else (n ^ k).bit_count()
