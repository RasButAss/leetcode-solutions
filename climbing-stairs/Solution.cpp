// https://leetcode.com/problems/climbing-stairs

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> f(++n + 1);
    f[1] = 1;
    for (int i = 2; i <= n; ++i) f[i] = f[i - 1] + f[i - 2];
    return f[n];
  }
};
