// https://leetcode.com/problems/palindrome-number

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    long long xx = x, rev = 0;
    while (xx) rev = rev * 10 + xx % 10, xx /= 10;
    return x == rev;
  }
};
