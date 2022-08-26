// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int cur = 0, bad = 0;
    for (int x : nums) bad = min(bad, cur += x);
    return 1 - bad;
  }
};
