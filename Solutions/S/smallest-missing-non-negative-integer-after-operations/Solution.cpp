// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/

class Solution {
 public:
  int findSmallestInteger(vector<int>& nums, int value) {
    unordered_map<int, int> cnt;
    for (int x : nums) ++cnt[((x % value) + value) % value];
    int best = 0, bestcnt = cnt[0];
    for (int i = 0; i < value; ++i) {
      if (cnt[i] < bestcnt) bestcnt = cnt[best = i];
      if (!bestcnt) return i;
    }
    return bestcnt * value + best;
  }
};
