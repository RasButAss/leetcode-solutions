// https://leetcode.com/problems/maximum-erasure-value

class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int best = 0;
    unordered_set<int> seen;
    for (int i = 0, j = 0, cur = 0, N = nums.size();; ++j) {
      if (j == N) {
        best = max(best, cur);
        break;
      } else if (seen.count(nums[j])) {
        best = max(best, cur);
        do {
          cur -= nums[i];
          seen.erase(nums[i]);
        } while (nums[i++] != nums[j]);
      }
      seen.insert(nums[j]);
      cur += nums[j];
    }
    return best;
  }
};
