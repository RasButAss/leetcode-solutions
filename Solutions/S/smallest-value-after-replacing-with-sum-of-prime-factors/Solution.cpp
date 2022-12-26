// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/

class Solution {
 public:
  int smallestValue(int n) {
    int x{}, nn = n;
    for (int p = 2; p * p <= n; ++p) {
      while (!(n % p)) n /= p, x += p;
    }
    if (n > 1) x += n;
    return x == nn ? x : smallestValue(x);
  }
};
