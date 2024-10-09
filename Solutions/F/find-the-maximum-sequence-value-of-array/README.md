# Find the maximum sequence value of array

[Problem link](https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/)

## Solutions


### Solution.py
```py
# https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/

class Solution:
    def maxValue(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def early(ar):
            poss = [[0] * (k + 1) for _ in range(128)]
            poss[0][0] = 1
            first = {}
            for i, x in enumerate(ar):
                for l in range(k - 1, -1, -1):
                    for j in range(128):
                        if poss[j][l]:
                            poss[j | x][l + 1] = 1
                for j in range(128):
                    if poss[j][k] and j not in first:
                        first[j] = i
            return first

        left, right = early(nums), early(nums[::-1])
        ret = 0
        for i in range(128):
            for j in range(128):
                if i in left and j in right and left[i] + right[j] < n - 1:
                    ret = max(ret, i ^ j)
        return ret
```
## Tags

* [Dynamic programming](/Collections/dynamic-programming.md#dynamic-programming) > [Array reuse](/Collections/dynamic-programming.md#array-reuse)
* [Dynamic programming](/Collections/dynamic-programming.md#dynamic-programming) > [Knapsack](/Collections/dynamic-programming.md#knapsack)
* [Array scanning](/Collections/array-scanning.md#array-scanning) > [From both ends of array](/Collections/array-scanning.md#from-both-ends-of-array)
* [Greedy](/Collections/greedy.md#greedy)
* [Bitwise operation](/Collections/bitwise-operation.md#bitwise-operation)