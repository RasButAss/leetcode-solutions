# https://leetcode.com/problems/modify-the-matrix/

class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        maxvals = [
            max(matrix[i][j] for i in range(m))
            for j in range(n)
        ]
        return [
            [
                maxvals[j] if matrix[i][j] == -1 else matrix[i][j]
                for j in range(n)
            ]
            for i in range(m)
        ]
