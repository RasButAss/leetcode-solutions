// https://leetcode.com/problems/product-of-array-except-self

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int N = nums.size();
    auto ret = vector<int>(N, 1);
    for (int i = 0, cum = 1; i < N - 1; i++) {
      cum *= nums[i];
      ret[i + 1] *= cum;
    }
    for (int i = N - 1, cum = 1; i > 0; i--) {
      cum *= nums[i];
      ret[i - 1] *= cum;
    }
    return ret;
  }
};
