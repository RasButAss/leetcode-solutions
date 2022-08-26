// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size(), bad = 0;
    for (int i = 0, j = N - 1; i < j; ++i, --j)
      bad = max(bad, nums[i] + nums[j]);
    return bad;
  }
};
