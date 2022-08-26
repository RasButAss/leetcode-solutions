// https://leetcode.com/problems/maximum-number-of-pairs-in-array

class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    unordered_set<int> seen;
    int cnt = 0;
    for (int x : nums) {
      if (seen.count(x))
        seen.erase(x), ++cnt;
      else
        seen.insert(x);
    }
    int single = seen.size();
    return {cnt, single};
  }
};
