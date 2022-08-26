// https://leetcode.com/problems/nth-magical-number

class Solution {
 public:
  int nthMagicalNumber(long long n, long long a, long long b) {
    long long l = a * b / gcd(a, b);

    long long start = 0, end = n * max(a, b);
    while (end - start > 1) {
      auto mid = (start + end) >> 1;
      auto cur = mid / a + mid / b - mid / l;
      ((cur < n) ? start : end) = mid;
    }
    return end % 1'000'000'007;
  }
};
