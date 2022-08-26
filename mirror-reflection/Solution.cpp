// https://leetcode.com/problems/mirror-reflection

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    if (q == 0)
      return 0;
    else if (q == p)
      return 1;

    int N = p / __gcd(p, q), M = N * q / p;
    return (N & 1) ? (M & 1) : 2;
  }
};
