// https://leetcode.com/problems/powx-n

class Solution {
 public:
  double myPow(double x, int nn) {
    long long n = nn;
    if (n < 0) {
      x = 1 / x;
      n = -n;
    }

    double ret = 1;
    while (n) {
      if (n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }

    return ret;
  }
};
