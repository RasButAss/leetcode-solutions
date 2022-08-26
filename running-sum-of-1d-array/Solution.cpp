// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    int prev = 0;
    for (int& n : nums) {
      n += prev;
      prev = n;
    }
    return nums;
  }
};
