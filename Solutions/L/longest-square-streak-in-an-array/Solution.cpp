// https://leetcode.com/problems/longest-square-streak-in-an-array/

class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    unordered_map<long long, int> cnt;
    int best = 0;
    for (int i : nums) best = max(best, cnt[i] = cnt[(long long)i * i] + 1);
    return best == 1 ? -1 : best;
  }
};
