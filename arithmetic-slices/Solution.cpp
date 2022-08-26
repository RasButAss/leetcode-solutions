// https://leetcode.com/problems/arithmetic-slices

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int ret = 0;
    for (int i = 1, N = A.size(), d = 0, c = 0; i < N; ++i) {
      int cur = A[i] - A[i - 1];
      if (cur == d) {
        if (++c > 1) ret += c - 1;
      } else {
        d = cur;
        c = 1;
      }
    }
    return ret;
  }
};
